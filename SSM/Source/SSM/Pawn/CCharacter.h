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

public:
	DECLARE_MULTICAST_DELEGATE_TwoParams( FOnChangedFireCount, ESkillType /*skill*/, int32 /*fireCount*/ );
	FOnChangedFireCount OnChangedFireCount;

	DECLARE_MULTICAST_DELEGATE_OneParam( FOnChangeChargingFirePercent, float /*percent*/ )
	FOnChangeChargingFirePercent OnChangeChargingFirePercent;

	DECLARE_MULTICAST_DELEGATE( FOnResetFireCount )
	FOnResetFireCount OnResetFireCount;
	
private:
	UPROPERTY( VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = true) )
	class UCameraComponent* _SideViewCameraComponent;

	UPROPERTY( VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = true) )
	class USpringArmComponent* _CameraBoom;

	UPROPERTY( EditAnywhere, BlueprintReadWrite, Category = C_Projectile, meta = (AllowPrivateAccess = true) )
	TMap<ESkillType, TSubclassOf<ACProjectile>> _ProjectileClassMap;

	UPROPERTY( EditAnywhere, BlueprintReadWrite, Category = C_Projectile, meta = (AllowPrivateAccess = true) )
	bool _ShowDebug = true;

	TMap<ESkillType, int32> _FireCount;
	
public:
	ACCharacter();

	virtual void PawnStartFire( uint8 FireModeNum ) override;
	
	FORCEINLINE class UCameraComponent* GetSideViewCameraComponent() const { return _SideViewCameraComponent; }
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return _CameraBoom; }

	void ChangeChargingFirePercent( float percent );
	void ResetFireCount();

private:
	void _SetFireCount( ESkillType skill, int fireCount );
};
