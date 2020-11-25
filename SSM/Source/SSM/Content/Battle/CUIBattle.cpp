// Copyright 2020 Pulsar, Inc. All Rights Reserved.

#include "CUIBattle.h"
#include "CCharacter.h"
#include "Components/Button.h"
#include "Battle/CBattleDefine.h"


void UCUIBattle::NativeConstruct()
{
	Super::NativeConstruct();

	c_pgb_charging->SetPercent( 0.f );

	c_txt_fire_cnt_1->SetText( FText::FromString( TEXT( "0" ) ) );
	c_txt_fire_cnt_2->SetText( FText::FromString( TEXT( "0" ) ) );
	c_txt_fire_cnt_3->SetText( FText::FromString( TEXT( "0" ) ) );
	c_txt_fire_cnt_4->SetText( FText::FromString( TEXT( "0" ) ) );

	c_btn_reset_fire_cnt->OnReleased.AddDynamic( this, &UCUIBattle::_OnClickResetFireCount );

	auto* myCharacter = Helper::GetMyCharacter<ACCharacter>( GetWorld() );
	if( ensure( myCharacter ) == true )
	{
		myCharacter->OnChangedFireCount.AddUObject( this, &UCUIBattle::_OnChangeFireCount );
		myCharacter->OnChangeChargingFirePercent.AddUObject( this, &UCUIBattle::_OnChangeChargingFirePercent );
	}
}

void UCUIBattle::NativeDestruct()
{
	c_btn_reset_fire_cnt->OnReleased.RemoveDynamic( this, &UCUIBattle::_OnClickResetFireCount );

	auto* myCharacter = Helper::GetMyCharacter<ACCharacter>( GetWorld() );
	if( IsValid( myCharacter ) == true )
	{
		myCharacter->OnChangedFireCount.RemoveAll( this );
		myCharacter->OnChangeChargingFirePercent.RemoveAll( this );
	}
}

void UCUIBattle::_OnChangeChargingFirePercent( float percent )
{
	if( percent <= 0 )
	{
		c_pgb_charging->SetVisibility( ESlateVisibility::Collapsed );
	}
	else
	{
		c_pgb_charging->SetVisibility( ESlateVisibility::Visible );
		c_pgb_charging->SetPercent( percent );
	}
}

void UCUIBattle::_OnChangeFireCount( ESkillType skill, int32 fireCount )
{
	UTextBlock* txtFireCount = nullptr;
	
	switch( skill )
	{
	case ESkillType::Special_1: { txtFireCount = c_txt_fire_cnt_1; } break;
	case ESkillType::Special_2: { txtFireCount = c_txt_fire_cnt_2; } break;
	case ESkillType::Special_3: { txtFireCount = c_txt_fire_cnt_3; } break;
	case ESkillType::Special_4: { txtFireCount = c_txt_fire_cnt_4; } break;
	default: break;
	}

	if( IsValid( txtFireCount ) == false )
	{
		UE_LOG( LogSSM, Error, TEXT( "[%s] Invalid ESkillType~! [%s]" ), P_FUNCTION, *P_ENUM_TO_STRING( ESkillType, skill ) );
		return;
	}

	txtFireCount->SetText( FText::FromString( FString::Printf( TEXT( "%d" ), fireCount ) ) );
}

void UCUIBattle::_OnClickResetFireCount()
{
	auto* myCharacter = Helper::GetMyCharacter<ACCharacter>( GetWorld() );
	if( IsValid( myCharacter ) == true )
	{
		myCharacter->ResetFireCount();
	}
}
