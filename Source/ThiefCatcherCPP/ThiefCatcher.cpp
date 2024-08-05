// Fill out your copyright notice in the Description page of Project Settings.


#include "ThiefCatcher.h"

// Sets default values
AThiefCatcher::AThiefCatcher(): Super()
{
	JumpAnimationInPlayRate = 1.0f;

	// Initialize SpringArm component
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->TargetArmLength = 500.0f;
	SpringArm->bUsePawnControlRotation = true;

	// Initialize Camera component
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("MainCamera"));
	Camera->SetupAttachment(SpringArm);
	Camera->bUsePawnControlRotation = true;

	// Disable controller rotation
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
}

void AThiefCatcher::SetupPlayerInputComponent(UInputComponent* MyPlayerInput)
{
	Super::SetupPlayerInputComponent(MyPlayerInput);

	// Bind movement inputs
	MyPlayerInput->BindAxis("MoveForwardBackward", this, &AThiefCatcher::MoveForwardBackward);
	MyPlayerInput->BindAxis("MoveRightLeft", this, &AThiefCatcher::MoveRightLeft);

	// Bind look inputs
	MyPlayerInput->BindAxis("Turn", this, &AThiefCatcher::AddControllerYawInput);
	MyPlayerInput->BindAxis("LookUpDown", this, &AThiefCatcher::AddControllerPitchInput);

	// Bind action inputs
	MyPlayerInput->BindAction("Jump", IE_Pressed, this, &AThiefCatcher::Jump);
	MyPlayerInput->BindAction("Jump", IE_Released, this, &AThiefCatcher::StopJump);

	MyPlayerInput->BindAction("Sprint", IE_Pressed, this, &AThiefCatcher::Sprint);
	MyPlayerInput->BindAction("Sprint", IE_Released, this, &AThiefCatcher::StopSprint);
}

void AThiefCatcher::MoveForwardBackward(const float Value)
{
	const FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
	AddMovementInput(Direction, Value);
}

void AThiefCatcher::MoveRightLeft(const float Value)
{
	const FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
	AddMovementInput(Direction, Value);
}

void AThiefCatcher::Jump()
{
	Super::Jump();
	bPressedJump = true;

	if (JumpAnimation)
	{
		PlayAnimMontage(JumpAnimation, JumpAnimationInPlayRate, NAME_None);
	}
}

void AThiefCatcher::StopJump()
{
	bPressedJump = false;
}


// ======= Sprint ======= 	
// TODO: Move sprint to its own components


void AThiefCatcher::Sprint()
{
	// Implementation needed
}

void AThiefCatcher::StopSprint()
{
	// Implementation needed
}
