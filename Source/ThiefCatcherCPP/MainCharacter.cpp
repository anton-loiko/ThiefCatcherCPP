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
	return CharacterStamina; 
}

float AMainCharacter::AddStamina()
{
	CharacterStamina += 1;

	return CharacterStamina;
}

float AMainCharacter::DecreaseStamina()
{
	CharacterStamina -= 1;

	return CharacterStamina;
}

bool AMainCharacter::StaminaIsZero()
{
	if (CharacterStamina <= 0)
	{
		bIsTired = true;

		GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	}

	UGameplayStatics::SpawnSoundAtLocation(this, TiredSound, GetActorLocation());

	return bIsTired;
}
