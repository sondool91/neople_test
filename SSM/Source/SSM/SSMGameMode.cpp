// Copyright Epic Games, Inc. All Rights Reserved.

#include "SSMGameMode.h"
#include "SSMCharacter.h"
#include "UObject/ConstructorHelpers.h"

ASSMGameMode::ASSMGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/SideScrollerCPP/Blueprints/SideScrollerCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
