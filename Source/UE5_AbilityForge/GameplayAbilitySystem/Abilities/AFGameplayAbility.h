// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "AFGameplayAbility.generated.h"

/**
 * 
 */
UCLASS()
class UE5_ABILITYFORGE_API UAFGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:

	UAFGameplayAbility();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
	bool ShouldShowInAbilitiesBar = false;
	
};
