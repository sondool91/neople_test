// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CCharacter.generated.h"


class ACProjectile;
enum class ESkillType : unsigned char;


UCLASS( config = Game )
class ACCharacter : public ACharacter
{
	GENERATED_BODY()

private:
	UPROPERTY( VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = true) )
	class UCameraComponent* _SideViewCameraComponent;

	UPROPERTY( VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = true) )
	class USpringArmComponent* _CameraBoom;

	UPROPERTY( EditAnywhere, BlueprintReadWrite, Category = C_Projectile, meta = (AllowPrivateAccess = true) )
	TMap<ESkillType, TSubclassOf<ACProjectile>> _ProjectileClassMap;

	UPROPERTY( EditAnywhere, BlueprintReadWrite, Category = C_Projectile, meta = (AllowPrivateAccess = true) )
	bool _ShowDebug = true;
	
public:
	ACCharacter();

	void FireSkill( ESkillType skill );

	FORCEINLINE class UCameraComponent* GetSideViewCameraComponent() const { return _SideViewCameraComponent; }
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return _CameraBoom; }
};
