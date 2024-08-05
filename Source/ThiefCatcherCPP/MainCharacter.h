// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MainCharacter.generated.h"

/**
 * AMainCharacter is a character class responsible for handling stamina, sound,
 * and animation related to the character's state.
 */
UCLASS()
class THIEFCATCHERCPP_API AMainCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMainCharacter();

	/**
	 * The current stamina of the character.
	 *
	 * Category: "CharacterStamina"
	 *
	 * BluePrint:
	 * - Editable only by default
	 */
	UPROPERTY(EditDefaultsOnly, Category = "CharacterStamina")
	float CharacterStamina;

	/**
	 * Indicates if the character is tired.
	 */
	bool bIsTired;

	/**
	 * Get the current stamina percentage.
	 * 
	 * @return The current stamina as a percentage.
	 */
	float GetStaminaPercent() const;

	/**
	 * Increase the character's stamina.
	 * 
	 * @return The updated stamina value.
	 */
	float AddStamina();

	/**
	 * Decrease the character's stamina.
	 * 
	 * @return The updated stamina value.
	 */
	float DecreaseStamina();

	/**
	 * Check if the character's stamina has reached zero.
	 * 
	 * This method also handles the character's tired state and plays the corresponding sound.
	 * 
	 * @return True if stamina is zero, otherwise false.
	 */
	bool StaminaIsZero();

	/**
	 * Sound played when the character is tired.
	 *
	 * Category: "CharacterStamina"
	 *
	 * BluePrint:
	 * - Editable only by default
	 */
	UPROPERTY(EditDefaultsOnly, Category = "CharacterStamina")
	USoundBase* TiredSound;

	/**
	 * Animation played when the character is tired.
	 *
	 * Category: "CharacterStamina"
	 * 
	 * BluePrint:
	 * - Editable only by default
	 */
	UPROPERTY(EditDefaultsOnly, Category = "CharacterStamina")
	UAnimMontage* VertigoAnimation;
};
