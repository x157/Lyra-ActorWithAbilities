// Copyright 2022 xist.gg

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystem/Attributes/LyraHealthSet.h"
#include "XCLTargetDummyHealthSet.generated.h"


/**
 * XCL Target Dummy Health Set
 *
 * This attribute set will not allow the Target Dummy to go below 1 Health.
 */
UCLASS(BlueprintType, DisplayName="XCL Target Dummy Health Set")
class XCL_API UXCLTargetDummyHealthSet : public ULyraHealthSet
{
	GENERATED_BODY()

public:
	// Set Class Defaults
	UXCLTargetDummyHealthSet();

	//~ULyraHealthSet implementation
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PreAttributeBaseChange(const FGameplayAttribute& Attribute, float& NewValue) const override;
	//~End of ULyraHealthSet implementation

};
