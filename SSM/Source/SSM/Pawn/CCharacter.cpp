// Copyright Epic Games, Inc. All Rights Reserved.

#include "CCharacter.h"

#include "DrawDebugHelpers.h"
#include "SSM/SSM.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Battle/CBattleDefine.h"
#include "Components/SkeletalMeshComponent.h"
#include "SSM/Actor/CProjectile.h"


ACCharacter::ACCharacter()
{
	GetCapsuleComponent()->InitCapsuleSize( 42.f, 96.0f );

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	_CameraBoom = CreateDefaultSubobject<USpringArmComponent>( TEXT( "_CameraBoom" ) );
	_CameraBoom->SetupAttachment( RootComponent );
	_CameraBoom->SetUsingAbsoluteRotation( true ); // Rotation of the character should not affect rotation of boom
	_CameraBoom->bDoCollisionTest = false;
	_CameraBoom->TargetArmLength = 500.f;
	_CameraBoom->SocketOffset = FVector( 0.f, 0.f, 75.f );
	_CameraBoom->SetRelativeRotation( FRotator( 0.f, 180.f, 0.f ) );

	_SideViewCameraComponent = CreateDefaultSubobject<UCameraComponent>( TEXT( "SideViewCamera" ) );
	_SideViewCameraComponent->SetupAttachment( _CameraBoom, USpringArmComponent::SocketName );
	_SideViewCameraComponent->bUsePawnControlRotation = false; // We don't want the controller rotating the camera

	GetCharacterMovement()->bOrientRotationToMovement = true; // Face in the direction we are moving..
	GetCharacterMovement()->RotationRate = FRotator( 0.0f, 720.0f, 0.0f ); // ...at this rotation rate
	GetCharacterMovement()->GravityScale = 2.f;
	GetCharacterMovement()->AirControl = 0.80f;
	GetCharacterMovement()->JumpZVelocity = 1000.f;
	GetCharacterMovement()->GroundFriction = 3.f;
	GetCharacterMovement()->MaxWalkSpeed = 600.f;
	GetCharacterMovement()->MaxFlySpeed = 600.f;

	_FireCount.Add( ESkillType::Special_1, 0 );
	_FireCount.Add( ESkillType::Special_2, 0 );
	_FireCount.Add( ESkillType::Special_3, 0 );
	_FireCount.Add( ESkillType::Special_4, 0 );
}

void ACCharacter::PawnStartFire(uint8 FireModeNum)
{
	ESkillType skill = static_cast<ESkillType>(FireModeNum);
	if( ensure( skill != ESkillType::None ) == false )
		return;

	if( false == _ProjectileClassMap.Contains( skill ) )
	{
		ensureMsgf( false, TEXT( "Cannot found ProjectileClass by SkillType[%s]~!" ), *P_ENUM_TO_STRING( ESkillType, skill ) );
		return;
	}

	auto fireTransform = ACProjectile::MakeFireTransform( GetMesh()->GetComponentLocation(), 
														  GetActorRotation(),
														  FVector( 0.f, 20.f, 50.f ) );
	float launchSpeed = 100.f;
	FVector velocity = GetActorRotation().Vector() * launchSpeed;

	FFireParams fireParam;
	fireParam.Velocity = velocity;
	fireParam.ProjectileClass = _ProjectileClassMap[skill];

	auto* newProjectile = ACProjectile::Create( GetWorld(), this, fireTransform, fireParam );
	if( false == IsValid( newProjectile ) )
		return;

	_SetFireCount( skill, _FireCount[skill] + 1 );

	if( _ShowDebug == true )
	{
		auto startLoc = fireTransform.GetRotation().Vector() + fireTransform.GetLocation();
		auto endLoc = fireTransform.GetRotation().Vector() * 1000.f + fireTransform.GetLocation();
		DrawDebugPoint( GetWorld(), startLoc, 10.f, FColor::Green, false, 3.f );
		DrawDebugPoint( GetWorld(), endLoc, 10.f, FColor::Green, false, 3.f );
		DrawDebugLine( GetWorld(), startLoc, endLoc, FColor::Blue, false, 3.f );
	}
}

void ACCharacter::ChangeChargingFirePercent( float percent )
{
	if( OnChangeChargingFirePercent.IsBound() == true )
		OnChangeChargingFirePercent.Broadcast( percent );
}

void ACCharacter::ResetFireCount()
{
	for( auto& pair : _FireCount )
	{
		_SetFireCount( pair.Key, 0 );
	}
}

void ACCharacter::_SetFireCount(ESkillType skill, int fireCount)
{
	if( _FireCount.Contains( skill ) == false )
		return;
	
	_FireCount[skill] = fireCount;

	if( OnChangedFireCount.IsBound() == true )
		OnChangedFireCount.Broadcast( skill, _FireCount[skill] );
}
