// Copyright Epic Games, Inc. All Rights Reserved.

#include "CPlayerController.h"

#include "Battle/CBattleDefine.h"
#include "GameFramework/PlayerInput.h"


const static FName INPUT_FIRE_1 = "Fire1";
const static FName INPUT_FIRE_2 = "Fire2";

ACPlayerController::ACPlayerController(const FObjectInitializer& ObjectInitializer)
	: Super( ObjectInitializer )
	, _InputLimitSecFor_Skill_1( 3.f )
	, _InputLimitSecFor_Skill_3( 1.f )
{
}

void ACPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	
	check( InputComponent );

	InputComponent->BindAxis( "MoveRight", this, &ACPlayerController::_OnMoveRight );

	InputComponent->BindAction( "Jump", IE_Pressed, this, &ACPlayerController::_OnJump );
	InputComponent->BindAction( "Jump", IE_Released, this, &ACPlayerController::_OnJumpStop );

	InputComponent->BindAction( INPUT_FIRE_1, IE_Pressed, this, &ACPlayerController::_OnFire1 );
	InputComponent->BindAction( INPUT_FIRE_1, IE_Released, this, &ACPlayerController::_OnFire1 );
	InputComponent->BindAction( INPUT_FIRE_2, IE_Pressed, this, &ACPlayerController::_OnFire2 );
	InputComponent->BindAction( INPUT_FIRE_2, IE_Released, this, &ACPlayerController::_OnFire2 );
}

FKey ACPlayerController::GetActionNameToKey( FName actionName )
{
	if( PlayerInput == nullptr )
		return EKeys::Invalid;
	
	const auto& keys = PlayerInput->GetKeysForAction( actionName );
	if( ensure( keys.Num() >= 1 ) == false )
		return EKeys::Invalid;

	return keys[0].Key;
}

FKeyState* ACPlayerController::GetKeyState(FName actionName)
{
	if( PlayerInput == nullptr )
		return nullptr;
	
	FKey key = GetActionNameToKey( actionName );
	auto* keyState = PlayerInput->GetKeyState( key );
	return keyState;
}

void ACPlayerController::_OnJump()
{
	GetCCharacter()->Jump();
}

void ACPlayerController::_OnJumpStop()
{
	GetCCharacter()->StopJumping();
}

void ACPlayerController::_OnMoveRight( float value )
{
	GetCCharacter()->AddMovementInput( FVector( 0.f, -1.f, 0.f ), value );
}

void ACPlayerController::_OnFire1()
{
	if( IsValid( GetWorld() ) == false )
		return;

	ESkillType skill = _DecideSkillToFire( INPUT_FIRE_1 );
	if( skill != ESkillType::None )
		GetCCharacter()->FireSkill( skill );
}

void ACPlayerController::_OnFire2()
{
	if( IsValid( GetWorld() ) == false )
		return;

	ESkillType skill = _DecideSkillToFire( INPUT_FIRE_2 );
	if( skill != ESkillType::None )
		GetCCharacter()->FireSkill( skill );
}

ESkillType ACPlayerController::_DecideSkillToFire( FName actionName )
{
	if( PlayerInput == nullptr )
		return ESkillType::None;
	
	ESkillType skill = ESkillType::None;
	
	FKey key1 = GetActionNameToKey( INPUT_FIRE_1 );
	FKey key2 = GetActionNameToKey( INPUT_FIRE_2 );
	
	if( actionName == INPUT_FIRE_1 )
	{
		if( true == WasInputKeyJustReleased( key1 ) )
		{
			auto* keyState = GetKeyState( INPUT_FIRE_1 );
			float durationSec = GetWorld()->GetRealTimeSeconds() - keyState->LastUpDownTransitionTime;
			if( durationSec < _InputLimitSecFor_Skill_1 )
				skill = ESkillType::Special_1;
			else
				skill = ESkillType::Special_2;

			UE_LOG( LogSSM, Verbose, TEXT( "Release...1 durationSec[%.3]" ), durationSec );
		}
	}
	else if( actionName == INPUT_FIRE_2 )
	{
		auto* keyState = GetKeyState( INPUT_FIRE_2 );

		if( true == WasInputKeyJustPressed( key2 ) &&
			true == IsInputKeyDown( key1 ) )
		{			
			float durationSec = GetWorld()->GetRealTimeSeconds() - keyState->LastUpDownTransitionTime;
			if( durationSec < _InputLimitSecFor_Skill_3 )
			{
				skill = ESkillType::Special_3;
			}
		}

		if( true == WasInputKeyJustReleased( key2 ) &&
			skill == ESkillType::None )
		{
			skill = ESkillType::Special_4;
		}
	}

	if( skill != ESkillType::None )
	{
		UE_LOG( LogSSM, Log, TEXT( "[%s] Skill[%s] Fire1[%s][%.3f] Fire2[%s][%.3f]" ),
				P_FUNCTION,
				*P_ENUM_TO_STRING( ESkillType, skill ),
				PlayerInput->IsPressed( GetActionNameToKey( INPUT_FIRE_1 ) ) ? TEXT( "Pressed" ) : TEXT( "Released" ),
				PlayerInput->GetTimeDown( GetActionNameToKey( INPUT_FIRE_1 ) ),
				PlayerInput->IsPressed( GetActionNameToKey( INPUT_FIRE_2 ) ) ? TEXT( "Pressed" ) : TEXT( "Released" ),
				PlayerInput->GetTimeDown( GetActionNameToKey( INPUT_FIRE_2 ) ) );
	}

	return skill;
}
