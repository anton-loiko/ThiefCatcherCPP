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
	bIsSprint = true;
	GetCharacterMovement()->MaxWalkSpeed = 1200.0f;
	// DecreaseStamina();
}

void AThiefCatcher::StopSprint()
{
	bIsSprint = false;
	GetCharacterMovement()->MaxWalkSpeed = 600.0f;
	// IncreaseStamina();

	GEngine->AddOnScreenDebugMessage(
		-1,
		5.f,
		FColor::Purple,
		FString::Printf(TEXT("Sprint stoped"))
	);
}

void AThiefCatcher::DecreaseStamina()
{
	CurrentStamina -= MinusStamina;
	GEngine->AddOnScreenDebugMessage(
		-1,
		5.f,
		FColor::Red,
		FString::Printf(TEXT("Stamina decreased ==> %f"), CurrentStamina)
	);
}

void AThiefCatcher::IncreaseStamina()
{
	CurrentStamina += PlusStamina;
	GEngine->AddOnScreenDebugMessage(
		-1,
		5.f,
		FColor::Green,
		FString::Printf(TEXT("Stamina increased ==> %f"), CurrentStamina)
	);
}

void AThiefCatcher::Tick(const float DeltaTime)
{
	Super::Tick(DeltaTime);


	// if (bIsSprint && CurrentStamina > 0.f)
	// {
	// 	DecreaseStamina();
	// }
	// else if (!bIsSprint && CurrentStamina < 100.f)
	// {
	// 	IncreaseStamina();
	// }

	if (bIsSprint && CurrentStamina > 0.f && CurrentStamina <= 100.f)
	{
		DecreaseStamina();
	}

	if (!bIsSprint && CurrentStamina < 100.f)
	{
		IncreaseStamina();
	}

	if (FMath::IsNearlyZero(CurrentStamina))
	{
		StopSprint();
	}
}
