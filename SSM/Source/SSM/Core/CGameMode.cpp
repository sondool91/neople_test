// Copyright Epic Games, Inc. All Rights Reserved.

#include "CGameMode.h"
#include "CCharacter.h"
#include "CPlayerController.h"
#include "UObject/ConstructorHelpers.h"


ACGameMode::ACGameMode()
	: Super()
{
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/SideScrollerCPP/Blueprints/SideScrollerCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
		DefaultPawnClass = PlayerPawnBPClass.Class;

	PlayerControllerClass = ACPlayerController::StaticClass();
}
