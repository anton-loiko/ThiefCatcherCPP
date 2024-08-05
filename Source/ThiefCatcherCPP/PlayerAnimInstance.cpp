// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerAnimInstance.h"

// Initializes the animation instance
void UPlayerAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	// Attempt to get the pawn owner of this animation instance
	MyCharacter = TryGetPawnOwner();
}

// Updates the animation based on the elapsed time
void UPlayerAnimInstance::NativeUpdateAnimation(const float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if (MyCharacter != nullptr)
	{
		// Update the Speed variable based on the character's velocity
		Speed = MyCharacter->GetVelocity().Size();
	}
}
