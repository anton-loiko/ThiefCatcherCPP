// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "CharacterHUD.generated.h"

/**
 * ACharacterHUD manages the HUD (Heads-Up Display) for the game.
 * 
 * This class handles the display of user interface elements on the screen.
 */
UCLASS()
class THIEFCATCHERCPP_API ACharacterHUD : public AHUD
{
	GENERATED_BODY()

public:
	/**
	 * Default constructor for ACharacterHUD.
	 * Initializes any default values for this class.
	 */
	ACharacterHUD();


	/**
	 * Called when the game starts or when spawned.
	 * Sets up the HUD and initializes necessary components.
	 */
	virtual void BeginPlay() override;

	/**
	 * The class of the main HUD widget to be used.
	 * 
	 * This widget is displayed on the screen to provide game information to the player.
	 */
	TSubclassOf<class UUserWidget> MainHUD;
};
