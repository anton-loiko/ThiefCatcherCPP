// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterHUD.h"

#include "Blueprint/UserWidget.h"


ACharacterHUD::ACharacterHUD(): Super()
{
	// Find the class for the Stamina widget blueprint
	static ConstructorHelpers::FClassFinder<UUserWidget> WBPStamina(TEXT("/Game/Widgets/WBP_Stamina"));

	// Set the MainHUD class to the found widget blueprint class
	MainHUD = WBPStamina.Class;
}

void ACharacterHUD::BeginPlay()
{
	Super::BeginPlay();

	// Create the HUD widget using the MainHUD class
	if (UUserWidget* CharacterWidget = CreateWidget(GetWorld(), MainHUD))
	{
		// Add the created widget to the viewport, so it is visible
		CharacterWidget->AddToViewport();
	}
}
