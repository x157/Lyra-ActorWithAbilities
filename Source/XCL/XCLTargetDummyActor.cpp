// Copyright 2022 xist.gg

#include "XCLTargetDummyActor.h"

#include "XCLTargetDummyHealthSet.h"
#include "Log/XCLLog.h"


const FName AXCLTargetDummyActor::MeshComponentName = TEXT("MeshComponent");


AXCLTargetDummyActor::AXCLTargetDummyActor(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer
		.SetDefaultSubobjectClass<UXCLTargetDummyHealthSet>(HealthSetName)
		)
{
	MeshComponent = ObjectInitializer.CreateDefaultSubobject<USkeletalMeshComponent>(this, MeshComponentName);
	RootComponent = MeshComponent;
}


void AXCLTargetDummyActor::InitializeAbilitySystem()
{
	Super::InitializeAbilitySystem();

	// Initialize default values for Health Set

	// This will fail to work if you try to do it before Super::InitializeAbilitySystem()
	// Can't move this to the constructor for that reason.

	HealthSet->InitMaxHealth(100.f);
	HealthSet->InitHealth(1.f);
}


void AXCLTargetDummyActor::BeginPlay()
{
	Super::BeginPlay();

	XCL_ADEBUG(DEBUG_Abilities, TEXT("BeginPlay with Health = %.1f/%.1f"), HealthSet->GetHealth(), HealthSet->GetMaxHealth());
}
