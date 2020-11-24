// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CBattleDefine.generated.h"

//============================================================
// ESkillType : 스킬 종류
UENUM( BlueprintType, Category = "C_Battle" )
enum class ESkillType : uint8
{
	None = 0,
	
	Special_1,
	Special_2,
	Special_3,
	Special_4,
};
