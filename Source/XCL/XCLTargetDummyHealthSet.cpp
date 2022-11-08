// Copyright 2022 xist.gg

#include "XCLTargetDummyHealthSet.h"


UXCLTargetDummyHealthSet::UXCLTargetDummyHealthSet()
	: Super()
{
}


void UXCLTargetDummyHealthSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);

	if (Attribute == GetHealthAttribute())
	{
		// Do not allow Health to drop below 1
		NewValue = FMath::Max(NewValue, 1.0f);
	}
}


void UXCLTargetDummyHealthSet::PreAttributeBaseChange(const FGameplayAttribute& Attribute, float& NewValue) const
{
	Super::PreAttributeBaseChange(Attribute, NewValue);

	if (Attribute == GetHealthAttribute())
	{
		// Do not allow Health to drop below 1
		NewValue = FMath::Max(NewValue, 1.0f);
	}
}
