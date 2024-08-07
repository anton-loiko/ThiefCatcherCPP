// Fill out your copyright notice in the Description page of Project Settings.


#include "ThiefCatcher.h"

#include "GameFramework/CharacterMovementComponent.h"

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

	// Enable Tick for this actor
	PrimaryActorTick.bCanEverTick = true;
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
	// Calculate the direction vector for forward/backward movement based on the controller's rotation
	const FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);

	// Apply movement input in the calculated direction
	AddMovementInput(Direction, Value);
}

void AThiefCatcher::MoveRightLeft(const float Value)
{
	// Calculate the direction vector for right/left movement based on the controller's rotation
	const FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);

	// Apply movement input in the calculated direction
	AddMovementInput(Direction, Value);
}

void AThiefCatcher::Jump()
{
	// Call the base class implementation of Jump
	Super::Jump();
	bPressedJump = true;

	// If a jump animation is defined, play it
	if (JumpAnimation)
	{
		PlayAnimMontage(JumpAnimation, JumpAnimationInPlayRate, NAME_None);
	}
}

void AThiefCatcher::StopJump()
{
	// Stop jumping by resetting the jump flag
	bPressedJump = false;
}


// ======= Sprint ======= 	
// TODO: Move sprint to its own components


void AThiefCatcher::Sprint()
{
	// Set sprint flag
	bIsSprint = true;

	// Increase the character's movement speed
	GetCharacterMovement()->MaxWalkSpeed = 1200.0f;
}

void AThiefCatcher::StopSprint()
{
	// Reset sprint flag
	bIsSprint = false;

	// Revert the character's movement speed to normal
	GetCharacterMovement()->MaxWalkSpeed = 600.0f;

	// Display a debug message indicating that sprinting has stopped
	GEngine->AddOnScreenDebugMessage(
		-1,
		2.f,
		FColor::Purple,
		FString::Printf(TEXT("Sprint stoped"))
	);
}

void AThiefCatcher::DecreaseStamina()
{
	// Decrease the character's stamina
	CurrentStamina -= MinusStamina;

	// Display a debug message with the updated value
	GEngine->AddOnScreenDebugMessage(
		-1,
		2.f,
		FColor::Orange,
		FString::Printf(TEXT("Stamina decreased ==> %f"), CurrentStamina)
	);
}

void AThiefCatcher::IncreaseStamina()
{
	// Increase the character's stamina
	CurrentStamina += PlusStamina;

	// Display a debug message with the updated value
	GEngine->AddOnScreenDebugMessage(
		-1,
		2.f,
		FColor::Green,
		FString::Printf(TEXT("Stamina increased ==> %f"), CurrentStamina)
	);
}

void AThiefCatcher::Tick(const float DeltaTime)
{
	// Call the base class implementation of Tick
	Super::Tick(DeltaTime);

	// If sprinting and stamina is greater than zero, decrease stamina
	if (bIsSprint && CurrentStamina > 0.f)
	{
		DecreaseStamina();
	}
	// If not sprinting and stamina is less than 100, increase stamina
	else if (!bIsSprint && CurrentStamina < 100.f)
	{
		IncreaseStamina();
	}

	// Stop sprinting if stamina is nearly zero
	if (FMath::IsNearlyZero(CurrentStamina))
	{
		StopSprint();
	}
}
