// Copyright 2022 xist.gg

#include "XCLTargetDummyHealthSet.h"


UXCLTargetDummyHealthSet::UXCLTargetDummyHealthSet()
	: Super()
{
}


void UXCLTargetDummyHealthSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);

	if (Attribute == GetHealthAttribute() && NewValue < 1.f)
	{
		// Do not allow Health to drop below 1
		NewValue = 1.f;
	}
}


void UXCLTargetDummyHealthSet::PreAttributeBaseChange(const FGameplayAttribute& Attribute, float& NewValue) const
{
	Super::PreAttributeBaseChange(Attribute, NewValue);

	if (Attribute == GetHealthAttribute() && NewValue < 1.f)
	{
		// Do not allow Health to drop below 1
		NewValue = 1.f;
	}
}
