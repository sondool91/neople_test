// Copyright 2020 Pulsar, Inc. All Rights Reserved.

#pragma once

#include "Blueprint/UserWidget.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"
#include "CUIBattle.generated.h"


enum class ESkillType : unsigned char;
UCLASS( BlueprintType, Blueprintable )
class UCUIBattle : public UUserWidget
{
	GENERATED_BODY()

	//====================================================================
	// Variables : 순서 [static]->[virtual]->[member & event]
public:
	static constexpr auto RESOURCE_PATH = TEXT( "SideScrollerCPP/Blueprints/ui_battle" );
	
private:
	UPROPERTY( meta = (BindWidget) )
	UProgressBar* c_pgb_charging;

	UPROPERTY( meta = (BindWidget) )
	UTextBlock* c_txt_fire_cnt_1;
	
	UPROPERTY( meta = (BindWidget) )
	UTextBlock* c_txt_fire_cnt_2;
	
	UPROPERTY( meta = (BindWidget) )
	UTextBlock* c_txt_fire_cnt_3;
	
	UPROPERTY( meta = (BindWidget) )
	UTextBlock* c_txt_fire_cnt_4;

	UPROPERTY( meta = (BindWidget) )
	UButton* c_btn_reset_fire_cnt;
	
	//====================================================================
	// Functions : 순서 [생성/소멸자]->[static]->[virtual]->[member & event]
public:
protected:
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;
		
private:
	UFUNCTION()
	void _OnChangeChargingFirePercent( float percent );

	UFUNCTION()
	void _OnChangeFireCount( ESkillType skill, int32 fireCount );

	UFUNCTION()
	void _OnClickResetFireCount();
};