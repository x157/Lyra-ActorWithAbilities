// Copyright 2022 xist.gg
//
// THIS CODE WILL NOT COMPILE
// See README for more info: https://github.com/x157/Lyra-ActorWithAbilities

#pragma once

#include "CoreMinimal.h"
#include "XCLActorWithAbilitiesAndHealth.h"
#include "XCLTargetDummyActor.generated.h"


/**
 * XCL Target Dummy Actor
 *
 * This is an Immortal Actor with Abilities and Health.
 *
 * It will never go below 1 Health.
 */
UCLASS(DisplayName="XCL Target Dummy Actor")
class XCL_API AXCLTargetDummyActor : public AXCLActorWithAbilitiesAndHealth
{
	GENERATED_BODY()

public:
	// Set Class Defaults
	AXCLTargetDummyActor(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	//~UXCLActorWithAbilities implementation
	virtual void InitializeAbilitySystem() override;
	//~End of UXCLActorWithAbilities implementation

	//~AActor implementation
	virtual void BeginPlay() override;
	//~End of AActor implementation

	/** Get the actor's root skeletal mesh component */
	UFUNCTION(BlueprintPure)
	FORCEINLINE USkeletalMeshComponent* GetMesh() const { return MeshComponent; }

public:
	// Public Static Const Component Names
	const static FName MeshComponentName;

protected:
	/** Root Component is Skeletal Mesh */
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TObjectPtr<USkeletalMeshComponent> MeshComponent;

};
