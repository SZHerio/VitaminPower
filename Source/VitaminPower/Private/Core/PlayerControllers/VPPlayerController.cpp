// A Vitamin Power Game. All Rights Reserved.

#include "Core/PlayerControllers/VPPlayerController.h"
#include "InputMappingContext.h"
#include "InputAction.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Characters/VPBaseCharacter.h"
#include "Characters/Player/VPPlayerCharacter.h"

void AVPPlayerController::BeginPlay()
{
	Super::BeginPlay();

	InitMappingContext();
}

void AVPPlayerController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	InitPlayerCharacter();
}

void AVPPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	auto EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent);
	if(!EnhancedInputComponent) return;

	if(MoveInputAction)
	{
		EnhancedInputComponent->BindAction(MoveInputAction, ETriggerEvent::Triggered, this, &AVPPlayerController::Move);
	}
}

void AVPPlayerController::InitMappingContext()
{
	auto LocalPlayer = GetLocalPlayer();
	if(!LocalPlayer) return;

	auto PlayerInputSubsystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
	if(!PlayerInputSubsystem) return;

	PlayerInputSubsystem->ClearAllMappings();

	if(MappingContext)
	{
		PlayerInputSubsystem->AddMappingContext(MappingContext, 0);
	}
}

void AVPPlayerController::Move(const FInputActionValue& Val)
{
	if(!PlayerCharacter) return;

	const FVector2D MovementVector = Val.Get<FVector2D>();
	PlayerCharacter->Move(MovementVector);
}

void AVPPlayerController::InitPlayerCharacter()
{
	auto VPPlayerCharacter = Cast<AVPPlayerCharacter>(GetCharacter());
	if(!VPPlayerCharacter) return;

	PlayerCharacter = VPPlayerCharacter;
}
