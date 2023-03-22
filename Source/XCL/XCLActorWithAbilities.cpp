// Copyright 2022 xist.gg
//
// THIS CODE WILL NOT COMPILE
// See README for more info: https://github.com/x157/Lyra-ActorWithAbilities

#include "XCLActorWithAbilities.h"

#include "XCLAbilitySystemComponent.h"
#include "XCLAbilitySettings.h"
#include "AbilitySystem/LyraAbilitySet.h"
#include "Log/XCLLog.h"


const FName AXCLActorWithAbilities::AbilitySystemComponentName = TEXT("AbilitySystemComponent");


AXCLActorWithAbilities::AXCLActorWithAbilities(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	// Must replicate Actor for multiplayer
	bReplicates = true;

	AbilitySystemComponent = ObjectInitializer.CreateDefaultSubobject<UXCLAbilitySystemComponent>(this, AbilitySystemComponentName);
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	// AbilitySystemComponent needs to be updated at a high frequency.
	NetUpdateFrequency = 100.0f;
}


void AXCLActorWithAbilities::PostInitializeComponents()
{
	// BEFORE PostInit Components:
	InitializeAbilitySystem();

	// Now during PostInit Components, there is a functional ASC for other components to use
	Super::PostInitializeComponents();
}


void AXCLActorWithAbilities::BeginPlay()
{
	Super::BeginPlay();

	if (HasAuthority() && AbilitySetOnSpawn)
	{
		XCL_ADEBUG(DEBUG_Abilities, TEXT("Granting OnSpawn Ability Set [%s]"), *GetNameSafe(AbilitySetOnSpawn));

		AbilitySetOnSpawn->GiveToAbilitySystem(AbilitySystemComponent, &GrantedHandlesOnSpawn);
	}
}


void AXCLActorWithAbilities::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	UninitializeAbilitySystem();

	Super::EndPlay(EndPlayReason);
}


void AXCLActorWithAbilities::InitializeAbilitySystem()
{
	XCL_ADEBUG(DEBUG_Abilities, TEXT("Initializing Ability System"));

	// We expect this to have been set in the constructor
	check(IsValid(AbilitySystemComponent));

	// Initialize ASC on this Actor
	AbilitySystemComponent->InitAbilityActorInfo(this, this);
}


void AXCLActorWithAbilities::UninitializeAbilitySystem()
{
	XCL_ADEBUG(DEBUG_Abilities, TEXT("Uninitializing Ability System"));

	if (AbilitySystemComponent)
	{
		AbilitySystemComponent->CancelAbilities();
		AbilitySystemComponent->ClearAbilityInput();
		AbilitySystemComponent->RemoveAllGameplayCues();
		AbilitySystemComponent->ClearActorInfo();

		GrantedHandlesOnSpawn.TakeFromAbilitySystem(AbilitySystemComponent);
	}
}


UAbilitySystemComponent* AXCLActorWithAbilities::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}


ULyraAbilitySystemComponent* AXCLActorWithAbilities::GetLyraAbilitySystemComponentChecked() const
{
	check(AbilitySystemComponent);
	return AbilitySystemComponent;
}
