// Fill out your copyright notice in the Description page of Project Settings.


#include "AFGameplayAbility.h"

UAFGameplayAbility::UAFGameplayAbility()
{
	ActivationOwnedTags.AddTag(FGameplayTag::RequestGameplayTag(FName("GameplayAbility.Active")));
	ActivationBlockedTags.AddTag(FGameplayTag::RequestGameplayTag("State.Dead"));
}

bool UAFGameplayAbility::HasPC() const
{
	const APawn* PawnObject = Cast<APawn>(GetAvatarActorFromActorInfo());
	if (!PawnObject) {
		return false;
	}

	return PawnObject->GetController()->IsA<APlayerController>();
}
