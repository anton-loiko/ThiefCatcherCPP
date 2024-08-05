// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "PlayerAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class THIEFCATCHERCPP_API UPlayerAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

	// ReSharper disable once CppUE4ProbableMemoryIssuesWithUObject
	APawn* MyCharacter;

	/**
	 *  BluePrint:
	 *  - Editable only by default
	 *  - Read only 
	 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float Speed;
};
