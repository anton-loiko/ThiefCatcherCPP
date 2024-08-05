// Fill out your copyright notice in the Description page of Project Settings.


#include "ThiefCatcherGameMode.h"

// Sets default values for this GameMode's properties
AThiefCatcherGameMode::AThiefCatcherGameMode(): Super()
{
	// Find the class of the main character blueprint
	static ConstructorHelpers::FClassFinder<APawn>
		MainCharacterThiefCatcher(TEXT("/Game/Blueprints/BP_MyThiefCatcher"));

	// Set the default pawn class for this game mode
	DefaultPawnClass = MainCharacterThiefCatcher.Class;
}
