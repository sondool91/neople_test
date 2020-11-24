// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "GameFramework/PlayerController.h"
#include "CCharacter.h"

#include "CPlayerController.generated.h"


struct FKeyState;
enum class ESkillType : unsigned char;


UCLASS( config = Game, BlueprintType, Blueprintable )
class ACPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	UPROPERTY( EditAnywhere, Category = "C_Input", meta = (AllowPrivateAccess = true) )
	float _InputLimitSecFor_Skill_1;

	UPROPERTY( EditAnywhere, Category = "C_Input", meta = (AllowPrivateAccess = true) )
	float _InputLimitSecFor_Skill_3;
	
public:
	ACPlayerController( const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get() );

	ACCharacter* GetCCharacter() const;

	FKey GetActionNameToKey( FName actionName );
	FKeyState* GetKeyState( FName actionName );
	
protected:
	virtual void SetupInputComponent() override;

	void _OnJump();
	void _OnJumpStop();
	
	void _OnMoveRight( float value );
	
	void _OnFire1();
	void _OnFire2();
	
	ESkillType _DecideSkillToUse( FName actionName );
};


FORCEINLINE ACCharacter* ACPlayerController::GetCCharacter() const
{
	auto* character = Cast<ACCharacter>( GetCharacter() );
	ensureMsgf( character, TEXT( "Must need~! ACCharacter~!" ) );
	return character;
}

