// Copyright Epic Games, Inc. All Rights Reserved.

#include "CPlayerController.h"

#include "Battle/CBattleDefine.h"
#include "Battle/CUIBattle.h"
#include "GameFramework/PlayerInput.h"
#include "UObject/ConstructorHelpers.h"


const static FName INPUT_FIRE_1 = "Fire1";
const static FName INPUT_FIRE_2 = "Fire2";

ACPlayerController::ACPlayerController(const FObjectInitializer& ObjectInitializer)
	: Super( ObjectInitializer )
	, _InputLimitSecFor_Skill_2( 3.f )
	, _InputLimitSecFor_Skill_3( 1.f )
	, _HasSkipReleasedFire1( false )
	, _HasSkipReleasedFire2( false )
{
}

void ACPlayerController::BeginPlayingState()
{
	UE_LOG( LogSSM, Log, TEXT( "BeginPlayingState Time[%.3]" ), GetWorld()->GetTimeSeconds() );

	auto uiPath = FString::Printf( TEXT( "/Game/%s" ), UCUIBattle::RESOURCE_PATH );
	UClass* uiClass = ConstructorHelpersInternal::FindOrLoadClass( uiPath, UCUIBattle::StaticClass() );
	if( uiClass == nullptr )
	{
		UE_LOG( LogSSM, Error, TEXT( "[%s] Not Found UI ( %s ) " ), P_FUNCTION, *uiPath );
		return;
	}

	auto* ui = CreateWidget<UCUIBattle>( GetWorld(), uiClass );
	if( ui == nullptr )
	{
		UE_LOG( LogSSM, Error, TEXT( "[%s]Not Create UI ( %s )" ), P_FUNCTION, *uiPath );
		return;
	}

	ui->AddToViewport( static_cast<int32>(100) );

	FInputModeGameAndUI inputMode;
	inputMode.SetWidgetToFocus( ui->TakeWidget() );
	inputMode.SetLockMouseToViewportBehavior( EMouseLockMode::DoNotLock );
	SetInputMode( inputMode );
	bShowMouseCursor = true;
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

void ACPlayerController::Tick(float DeltaSeconds)
{
	FKey key1 = GetActionNameToKey( INPUT_FIRE_1 );
	if( true == IsInputKeyDown( key1 ) )
	{
		auto* keyState = GetKeyState( INPUT_FIRE_1 );
		float durationSec = GetWorld()->GetRealTimeSeconds() - keyState->LastUpDownTransitionTime;
		float percent = durationSec / _InputLimitSecFor_Skill_2;
		percent = FMath::Min( 1.f, percent );

		GetCCharacter()->ChangeChargingFirePercent( percent );
	}
	else
	{
		GetCCharacter()->ChangeChargingFirePercent( 0.f );
	}
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
		StartFire( static_cast<int32>(skill) );
}

void ACPlayerController::_OnFire2()
{
	if( IsValid( GetWorld() ) == false )
		return;

	ESkillType skill = _DecideSkillToFire( INPUT_FIRE_2 );
	if( skill != ESkillType::None )
		StartFire( static_cast<int32>(skill) );
}

ESkillType ACPlayerController::_DecideSkillToFire( FName actionName )
{
	if( PlayerInput == nullptr )
		return ESkillType::None;
	
	ESkillType skill = ESkillType::None;
	
	FKey key1 = GetActionNameToKey( INPUT_FIRE_1 );
	FKey key2 = GetActionNameToKey( INPUT_FIRE_2 );
	auto* keyState1 = GetKeyState( INPUT_FIRE_1 );
	auto* keyState2 = GetKeyState( INPUT_FIRE_2 );
	
	if( actionName == INPUT_FIRE_1 )
	{
		if( _HasSkipReleasedFire1 == true )
		{
			if( true == WasInputKeyJustReleased( key1 ) )
			{
				_HasSkipReleasedFire1 = false;
				skill = ESkillType::None;
			}
		}
		else
		{
			if( true == IsInputKeyDown( key1 ) )
			{
				float durationSec = GetWorld()->GetRealTimeSeconds() - keyState1->LastUpDownTransitionTime;
				float percent = durationSec / _InputLimitSecFor_Skill_2 * 100.f;

				GetCCharacter()->ChangeChargingFirePercent( percent );
			}
			else if( true == WasInputKeyJustReleased( key1 ) )
			{
				float durationSec = GetWorld()->GetRealTimeSeconds() - keyState1->LastUpDownTransitionTime;
				if( durationSec < _InputLimitSecFor_Skill_2 )
					skill = ESkillType::Special_1;
				else
					skill = ESkillType::Special_2;
			}
		}
	}
	else if( actionName == INPUT_FIRE_2 )
	{
		if( _HasSkipReleasedFire2 == true )
		{
			if( true == WasInputKeyJustReleased( key2 ) )
			{
				_HasSkipReleasedFire2 = false;
				skill = ESkillType::None;
			}
		}
		else
		{
			if( true == WasInputKeyJustPressed( key2 ) &&
				true == IsInputKeyDown( key1 ) )
			{
				float durationSec = GetWorld()->GetRealTimeSeconds() - keyState1->LastUpDownTransitionTime;
				if( durationSec < _InputLimitSecFor_Skill_3 )
				{
					skill = ESkillType::Special_3;

					// todo - SSM : playerInput 내부에 있는 Pressed 이벤트를 지워보려 했는데 찾지 못했습니다.
					// todo - SSM : 엔진을 수정해서 해당 Key의 이벤트를 날려주는 함수를 추가해봐야 할 듯 합니다.
					// todo - SSM : 일단 동작하게 하기 위해 아래 변수들 추가해서 임시 처리 했습니다.
					_HasSkipReleasedFire1 = true;
					_HasSkipReleasedFire2 = true;
				}
			}

			if( true == WasInputKeyJustReleased( key2 ) &&
				skill == ESkillType::None )
			{
				skill = ESkillType::Special_4;
			}
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
