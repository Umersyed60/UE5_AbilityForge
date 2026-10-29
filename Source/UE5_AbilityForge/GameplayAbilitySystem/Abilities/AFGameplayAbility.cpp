// Fill out your copyright notice in the Description page of Project Settings.


#include "AFGameplayAbility.h"

UAFGameplayAbility::UAFGameplayAbility()
{
	ActivationOwnedTags.AddTag(FGameplayTag::RequestGameplayTag(FName("GameplayAbility.Active")));
}
