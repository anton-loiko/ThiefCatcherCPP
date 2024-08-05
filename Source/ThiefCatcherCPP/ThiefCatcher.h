// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MainCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "ThiefCatcher.generated.h"

/**
 * AThiefCatcher is a character class that extends AMainCharacter.
 * It includes components for camera control and jump animations, as well as movement and sprint functionality.
 */
UCLASS()
class THIEFCATCHERCPP_API AThiefCatcher : public AMainCharacter
{
	GENERATED_BODY()

private:
	// Rate at which the jump animation is played
	float JumpAnimationInPlayRate;

public:
	// Sets default values for this character's properties
	AThiefCatcher();

	/**
	 * Spring arm component to position the camera behind the character.
	 *
	 * BluePrint:
	 * - Visible Anywhere
	 */
	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* SpringArm;

	/**
	 * Camera component to render the view from the character's perspective.
	 * 
	 * BluePrint:
	 * - Visible Anywhere
	 */
	UPROPERTY(VisibleAnywhere)
	UCameraComponent* Camera;

	/**
	 * Montage for jump animations.
	 *
	 * Category: "JumpAnimation"
	 * 
	 * BluePrint:
	 * - Edit Anywhere
	 * - Blueprint can Read & Write
	 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "JumpAnimation")
	UAnimMontage* JumpAnimation;

	// Overrides
	virtual void SetupPlayerInputComponent(UInputComponent* MyPlayerInput) override;

	// Movement

	void MoveForwardBackward(float Value);
	void MoveRightLeft(float Value);

	// Jumping

	virtual void Jump() override;
	void StopJump();


	// Sprinting 	
	// TODO: Move sprinting to its own components

	bool bIsSprint;
	float CurrentStamina;

	void Sprint();
	void StopSprint();
};
