// Fill out your copyright notice in the Description page of Project Settings.


#include "ThiefCatcherGameMode.h"

AThiefCatcherGameMode::AThiefCatcherGameMode(): Super()
{
	ConstructorHelpers::FClassFinder<APawn> MainCharacterThiefCatcher(TEXT("/Game/Blueprints/BP_MyThiefCatcher"));

	DefaultPawnClass = MainCharacterThiefCatcher.Class;
}
