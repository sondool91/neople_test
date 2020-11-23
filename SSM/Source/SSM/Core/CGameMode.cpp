// Copyright Epic Games, Inc. All Rights Reserved.

#include "CGameMode.h"
#include "CCharacter.h"
#include "UObject/ConstructorHelpers.h"

ACGameMode::ACGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/SideScrollerCPP/Blueprints/SideScrollerCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
