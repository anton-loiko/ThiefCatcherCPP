// Fill out your copyright notice in the Description page of Project Settings.

#include "MainCharacter.h"

#include "Components/CapsuleComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AMainCharacter::AMainCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	CharacterStamina = 100.0f;
	bIsTired = false;
}

float AMainCharacter::GetStaminaPercent() const
{
	// Returns the current stamina percentage
	return CharacterStamina;
}

float AMainCharacter::AddStamina()
{
	// Increase stamina by a specified amount and return the new value
	CharacterStamina += 1;
	return CharacterStamina;
}

float AMainCharacter::DecreaseStamina()
{
	// Decrease stamina by a specified amount and return the new value
	CharacterStamina -= 1;
	return CharacterStamina;
}

bool AMainCharacter::StaminaIsZero()
{
	// Check if stamina is depleted and update state accordingly
	if (CharacterStamina <= 0)
	{
		bIsTired = true;

		// Disable collision if character is tired
		GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	}

	// Play tired sound at the character's location
	UGameplayStatics::SpawnSoundAtLocation(this, TiredSound, GetActorLocation());

	return bIsTired;
}
