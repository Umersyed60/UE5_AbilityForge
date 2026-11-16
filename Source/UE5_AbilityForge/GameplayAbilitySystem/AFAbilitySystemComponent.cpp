// Fill out your copyright notice in the Description page of Project Settings.


#include "AFAbilitySystemComponent.h"
#include "Character/AFCharacterBase.h"

UAFAbilitySystemComponent::UAFAbilitySystemComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UAFAbilitySystemComponent::BeginPlay()
{
	Super::BeginPlay();
}

void UAFAbilitySystemComponent::OnRep_ActivateAbilities()
{
	Super::OnRep_ActivateAbilities();

	AAFCharacterBase *Character = Cast<AAFCharacterBase>(GetOwner());
	if (!Character) return;

	bool bAbilitiesChanged = false;
	if (LastActivatableAbilities.Num() != ActivatableAbilities.Items.Num()) {
		bAbilitiesChanged = true;
	}
	else {
		for (int32 i = 0; i < LastActivatableAbilities.Num(); i++) {
			if (LastActivatableAbilities[i].Ability != ActivatableAbilities.Items[i].Ability) {
				bAbilitiesChanged = true;
				break;
			}
		}
	}

	if (bAbilitiesChanged) {
		Character->SendAbilitiesChangedEvent();
		LastActivatableAbilities = ActivatableAbilities.Items;
	}
}

void UAFAbilitySystemComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}
