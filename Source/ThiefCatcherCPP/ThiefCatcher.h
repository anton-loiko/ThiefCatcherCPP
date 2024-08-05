// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MainCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "ThiefCatcher.generated.h"

/**
 * 
 */
UCLASS()
class THIEFCATCHERCPP_API AThiefCatcher : public AMainCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AThiefCatcher();

	/**
	 *  BluePrint:
	 *  - Visible Anywhere
	 */
	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* SpringArm;

	/**
	 *  BluePrint:
	 *  - Visible Anywhere
	 */
	UPROPERTY(VisibleAnywhere)
	UCameraComponent* Camera;

	virtual void SetupPlayerInputComponent(UInputComponent* MyPlayerInput) override;

	void MoveForwardBackward(float Value);

	void MoveRightLeft(float Value);

	virtual void Jump() override;

	void StopJump();
};
