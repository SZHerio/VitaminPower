// A Vitamin Power Game. All Rights Reserved.

#include "Core/GameModes/VPGameModeBase.h"
#include "Characters/Player/VPPlayerCharacter.h"
#include "Core/PlayerControllers/VPPlayerController.h"

AVPGameModeBase::AVPGameModeBase()
{
    DefaultPawnClass = AVPPlayerCharacter::StaticClass();
    PlayerControllerClass = AVPPlayerController::StaticClass();
}

