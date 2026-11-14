// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "AFGameplayAbility.generated.h"

/**
 * 
 */

UENUM(BlueprintType)
enum class EAbilityInputID : uint8
{
	None UMETA(DisplayName = "None"), //0
	PrimaryAbility UMETA(DisplayName = "Primary Ability"), //1
	SecondaryAbility UMETA(DisplayName = "Secondary Ability"), //2
	DefensiveAbility UMETA(DisplayName = "Defensive Ability"), //3
	MovementAbility UMETA(DisplayName = "Movement Ability"), //4
};

UCLASS()
class UE5_ABILITYFORGE_API UAFGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:

	UAFGameplayAbility();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
	bool ShouldShowInAbilitiesBar = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	EAbilityInputID AbilityInputID = EAbilityInputID::None;

private:
	UFUNCTION(BlueprintCallable, Category = "Helpers")
	bool HasPC() const;
};
