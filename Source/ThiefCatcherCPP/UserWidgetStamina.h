// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UserWidgetStamina.generated.h"


class AThiefCatcher;

/**
 * UUserWidgetStamina is a user interface widget class responsible for displaying 
 * and interacting with the stamina information of the player character.
 */
UCLASS()
class THIEFCATCHERCPP_API UUserWidgetStamina : public UUserWidget
{
	GENERATED_BODY()

public:
	/**
	  * Retrieves the current stamina of the player character as a percentage.
	  * 
	  * This function is callable in Blueprints and does not modify any data.
	  * 
	  * @return The stamina of the player character as a percentage (0.0 to 1.0).
	  */
	UFUNCTION(BlueprintCallable, BlueprintPure)
	float GetCharacterStamina();
};
