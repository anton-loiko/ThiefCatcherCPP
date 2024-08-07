// Fill out your copyright notice in the Description page of Project Settings.


#include "UserWidgetStamina.h"
#include "ThiefCatcher.h"
#include "Kismet/GameplayStatics.h"

// Returns the current stamina of the player character as a percentage
float UUserWidgetStamina::GetCharacterStamina()
{
	// Cast the player character to AThiefCatcher
	const AThiefCatcher* OurPlayer = Cast<AThiefCatcher>(
		UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)
	);

	// Check if the cast was unsuccessful
	if (!OurPlayer)
	{
		// If the cast failed, return 0 as a default value
		return 0.0f;
	}

	// Return the stamina as a percentage
	return OurPlayer->CurrentStamina / 100.f;;
}
