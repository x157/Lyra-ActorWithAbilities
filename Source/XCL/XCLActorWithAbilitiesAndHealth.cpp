// Copyright 2022 xist.gg
//
// THIS CODE WILL NOT COMPILE
// See README for more info: https://github.com/x157/Lyra-ActorWithAbilities

#include "Ability/XCLActorWithAbilitiesAndHealth.h"

#include "AbilitySystem/LyraAbilitySystemComponent.h"
#include "AbilitySystem/Attributes/LyraCombatSet.h"
#include "AbilitySystem/Attributes/LyraHealthSet.h"
#include "Character/LyraHealthComponent.h"
#include "Log/XCLLog.h"


const FName AXCLActorWithAbilitiesAndHealth::CombatSetName       = TEXT("CombatSet");
const FName AXCLActorWithAbilitiesAndHealth::HealthComponentName = TEXT("HealthComponent");
const FName AXCLActorWithAbilitiesAndHealth::HealthSetName       = TEXT("HealthSet");


AXCLActorWithAbilitiesAndHealth::AXCLActorWithAbilitiesAndHealth(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	CombatSet = ObjectInitializer.CreateDefaultSubobject<ULyraCombatSet>(this, CombatSetName);
	HealthSet = ObjectInitializer.CreateDefaultSubobject<ULyraHealthSet>(this, HealthSetName);

	HealthComponent = ObjectInitializer.CreateDefaultSubobject<ULyraHealthComponent>(this, HealthComponentName);
}


void AXCLActorWithAbilitiesAndHealth::InitializeAbilitySystem()
{
	// Super::InitializeAbilitySystem is required to get the ASC working, do this first:
	Super::InitializeAbilitySystem();

	// HealthComponent requires a Lyra based ASC
	ULyraAbilitySystemComponent* ASC = GetLyraAbilitySystemComponentChecked();

	// Add Attribute Sets to ASC
	ASC->AddAttributeSetSubobject(CombatSet.Get());
	ASC->AddAttributeSetSubobject(HealthSet.Get());

	// DO NOT init HealthComponent until AFTER HealthSet has been added
	HealthComponent->InitializeWithAbilitySystem(ASC);
}


void AXCLActorWithAbilitiesAndHealth::UninitializeAbilitySystem()
{
	HealthComponent->UninitializeFromAbilitySystem();

	if (UAbilitySystemComponent* ASC = GetAbilitySystemComponent())
	{
		ASC->RemoveSpawnedAttribute(CombatSet.Get());
		ASC->RemoveSpawnedAttribute(HealthSet.Get());
	}

	Super::UninitializeAbilitySystem();
}
