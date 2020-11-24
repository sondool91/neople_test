// Copyright Epic Games, Inc. All Rights Reserved.

#include "CCharacter.h"
#include "SSM/SSM.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Battle/CBattleDefine.h"


ACCharacter::ACCharacter()
{
	GetCapsuleComponent()->InitCapsuleSize( 42.f, 96.0f );

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>( TEXT( "CameraBoom" ) );
	CameraBoom->SetupAttachment( RootComponent );
	CameraBoom->SetUsingAbsoluteRotation( true ); // Rotation of the character should not affect rotation of boom
	CameraBoom->bDoCollisionTest = false;
	CameraBoom->TargetArmLength = 500.f;
	CameraBoom->SocketOffset = FVector( 0.f, 0.f, 75.f );
	CameraBoom->SetRelativeRotation( FRotator( 0.f, 180.f, 0.f ) );

	SideViewCameraComponent = CreateDefaultSubobject<UCameraComponent>( TEXT( "SideViewCamera" ) );
	SideViewCameraComponent->SetupAttachment( CameraBoom, USpringArmComponent::SocketName );
	SideViewCameraComponent->bUsePawnControlRotation = false; // We don't want the controller rotating the camera

	GetCharacterMovement()->bOrientRotationToMovement = true; // Face in the direction we are moving..
	GetCharacterMovement()->RotationRate = FRotator( 0.0f, 720.0f, 0.0f ); // ...at this rotation rate
	GetCharacterMovement()->GravityScale = 2.f;
	GetCharacterMovement()->AirControl = 0.80f;
	GetCharacterMovement()->JumpZVelocity = 1000.f;
	GetCharacterMovement()->GroundFriction = 3.f;
	GetCharacterMovement()->MaxWalkSpeed = 600.f;
	GetCharacterMovement()->MaxFlySpeed = 600.f;
}

void ACCharacter::UseSkill( ESkillType skill )
{
	if( ensure( skill != ESkillType::None ) )
		return;

	UE_LOG( LogSSM, Log, TEXT( "[%s] Skill[%s]" ), P_FUNCTION, *P_ENUM_TO_STRING( ESkillType, skill ) );
}
