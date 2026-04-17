// A Vitamin Power Game. All Rights Reserved.

#include "Core/GameModes/VPGameModeBase.h"
#include "Characters/Player/VPPlayerCharacter.h"
#include "Core/PlayerControllers/VPPlayerController.h"
#include "UI/VPHUD.h"

AVPGameModeBase::AVPGameModeBase()
{
    DefaultPawnClass = AVPPlayerCharacter::StaticClass();
    PlayerControllerClass = AVPPlayerController::StaticClass();
    HUDClass = AVPHUD::StaticClass();
}

