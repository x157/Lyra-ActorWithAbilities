// Copyright 2022 xist.gg

#pragma once

#include "CoreMinimal.h"
#include "XCLActorWithAbilitiesAndHealth.h"
#include "XCLTargetDummyActor.generated.h"


class UXCLPlayerInteractionComponent;


/**
 * XCL Target Dummy Actor
 */
UCLASS(DisplayName="XCL Target Dummy Actor")
class XCL_API AXCLTargetDummyActor : public AXCLActorWithAbilitiesAndHealth
{
	GENERATED_BODY()

public:
	// Set Class Defaults
	AXCLTargetDummyActor(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:
	/** Root Component is Skeletal Mesh */
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<USkeletalMeshComponent> MeshComponent;

};
