// Copyright 2022 xist.gg

#include "XCLTargetDummyActor.h"

#include "XCLTargetDummyHealthSet.h"


AXCLTargetDummyActor::AXCLTargetDummyActor(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer
		.SetDefaultSubobjectClass<UXCLTargetDummyHealthSet>(HealthSetName)
		)
{
	MeshComponent = ObjectInitializer.CreateDefaultSubobject<USkeletalMeshComponent>(this, TEXT("MeshComponent"));
	RootComponent = MeshComponent;
}
