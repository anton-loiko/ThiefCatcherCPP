// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "PlayerAnimInstance.generated.h"

/**
 * UPlayerAnimInstance is an animation instance class used for handling character animations.
 */
UCLASS()
class THIEFCATCHERCPP_API UPlayerAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	/**
	 * Initializes the animation instance. 
	 * This method is called when the animation instance is created.
	 */
	virtual void NativeInitializeAnimation() override;

	/**
	 * Updates the animation based on the elapsed time.
	 * 
	 * @param DeltaSeconds The time elapsed since the last update.
	 */
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

	// Pointer to the character associated with this animation instance.
	// ReSharper disable once CppUE4ProbableMemoryIssuesWithUObject
	APawn* MyCharacter;

	/**
	 * The speed of the character, used for animation purposes.
	 * 
	 * BluePrint:
	 * - Editable only by default
	 * - Read only 
	 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float Speed;
};
