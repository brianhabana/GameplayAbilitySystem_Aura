// Copyright Brian Habana


#include "Player/AuraPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Interaction/EnemyInterface.h"

AAuraPlayerController::AAuraPlayerController()
{
	bReplicates = true;
}

void AAuraPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
	CursorTrace();
}


void AAuraPlayerController::CursorTrace()
{
	FHitResult CursorHit;
	GetHitResultUnderCursor(ECC_Visibility,false, CursorHit);
	if (!CursorHit.bBlockingHit) return;

	LastActor = ThisActor;
	ThisActor = CursorHit.GetActor();

	/*
	 *Line trace from cursor. There are several scenarios
	 * A. LastActor is null && ThisActor is null
	 *  - Do Nothing
	 * B. LastActor is Null ** ThisActor is valid
	 *  - highlight this actor
	 * C. LastActor is valid && ThisActor is null
	 *  - Unhighlight last actor
	 * D. Both actors are valid, but last actor != ThisActor
	 *  - Unlightlast last actor, and Highlight ThisActor
	 * E. Both actors are valid, and are the same actor
	 *	- Do nothing
	 */

	bool	LastActorValid = false;
	bool	ThisActorValid = false;
	
	if (LastActor == nullptr)
	{
		LastActorValid = false;	
	}
	else
	{
		LastActorValid = true;
	}

	if(ThisActor == nullptr)
	{
		ThisActorValid = false;
	}
	else
	{
		ThisActorValid = true;
	}

	if (!LastActorValid && !ThisActorValid)
	{
		// do nothing
	}
	else if (!LastActorValid && ThisActorValid)
	{
		//case b
		ThisActor->HighlightActor();
	}
	else if (LastActorValid && !ThisActorValid)
	{
		//case c
		LastActor->UnHighlightActor();
	}
	else if ((LastActorValid && ThisActorValid) && (LastActor!= ThisActor))
	{
		//case d
		LastActor->UnHighlightActor();
		ThisActor->HighlightActor();
	}
	else if((LastActorValid && ThisActorValid) && (LastActor == ThisActor))
	{
		//case e
		// do nothing
	}
}

void AAuraPlayerController::BeginPlay()
{
	Super::BeginPlay();

	check(AuraContext);

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(Subsystem);
	Subsystem->AddMappingContext(AuraContext, 0);

	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;

	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);
}

void AAuraPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AAuraPlayerController::Move);
}

void AAuraPlayerController::Move(const FInputActionValue& InputActionValue)
{
	const FVector2d InputAxisVector = InputActionValue.Get<FVector2d>();
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	if (APawn* ControllerPawn = GetPawn<APawn>())
	{
		ControllerPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
		ControllerPawn->AddMovementInput(RightDirection, InputAxisVector.X);
	}
}

