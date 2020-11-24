// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CCharacter.generated.h"


enum class ESkillType : unsigned char;


UCLASS( config = Game )
class ACCharacter : public ACharacter
{
	GENERATED_BODY()

private:
	UPROPERTY( VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true") )
	class UCameraComponent* SideViewCameraComponent;

	UPROPERTY( VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true") )
	class USpringArmComponent* CameraBoom;
		
public:
	ACCharacter();

	void UseSkill( ESkillType skill );

	FORCEINLINE class UCameraComponent* GetSideViewCameraComponent() const { return SideViewCameraComponent; }
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
};
