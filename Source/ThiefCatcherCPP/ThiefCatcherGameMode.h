// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ThiefCatcherGameMode.generated.h"

/**
 * AThiefCatcherGameMode defines the game mode for the Thief Catcher game.
 * 
 * This class handles game-specific logic and settings for the game mode.
 */
UCLASS()
class THIEFCATCHERCPP_API AThiefCatcherGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	// Sets default values for this GameMode properties
	AThiefCatcherGameMode();
};
