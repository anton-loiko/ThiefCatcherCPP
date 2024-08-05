// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MainCharacter.generated.h"

UCLASS()
class THIEFCATCHERCPP_API AMainCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMainCharacter();

	/**
	 *  BluePrint:
	 *  - Editable only by default
	 */
	UPROPERTY(EditDefaultsOnly, Category = "CharacterStamina")
	float CharacterStamina;

	bool bIsTired;

	float GetStaminaPercent() const;
	float AddStamina();
	float DecreaseStamina();

	// Method that is responsible for the death of a character
	bool StaminaIsZero();

	/**
	 * Sound played at character death
	 *
	 *  BluePrint:
	 *  - Editable only by default
	 */
	UPROPERTY(EditDefaultsOnly, Category = "CharacterStamina")
	USoundBase* TiredSound;

	/**
	 * Animation played at character death
	 *
	 *  BluePrint:
	 *  - Editable only by default
	 */
	UPROPERTY(EditDefaultsOnly, Category = "CharacterStamina")
	UAnimMontage* VertigoAnimation;
};
