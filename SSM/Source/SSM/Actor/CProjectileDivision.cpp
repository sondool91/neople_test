// Copyright Epic Games, Inc. All Rights Reserved.

#include "CProjectileDivision.h"


ACProjectileDivision::ACProjectileDivision( const FObjectInitializer& ObjectInitializer )
	: Super( ObjectInitializer )
	, _DestroySelfOnSplit( true )
	, _SplitMaxCount( 1 )
{
}

void ACProjectileDivision::_Division()
{
	if( _DivisionCurrentCount >= _SplitMaxCount )
		return;
	
	_DivisionCurrentCount++;

	for( auto& rotOffset : _SplitOffsetRots )
	{
		FFireParams param = _FireParams;
		param.Velocity = rotOffset.RotateVector( _FireParams.Velocity );

		auto* projectile = Create( GetWorld(), GetOwner(), GetTransform(), param );
		if( false == IsValid( projectile ) )
			continue;

		auto* projectileSplit = Cast<ACProjectileDivision>( projectile );
		if( true == IsValid( projectileSplit ) )
			projectileSplit->_DivisionCurrentCount = _DivisionCurrentCount;
	}
}

void ACProjectileDivision::_OnTimeout()
{
	_Division();

	if( _DestroySelfOnSplit == true )
		Destroy();
}
