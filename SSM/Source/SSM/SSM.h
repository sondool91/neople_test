// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"


SSM_API DECLARE_LOG_CATEGORY_EXTERN( LogSSM, Log, All );

#define P_FUNCTION ANSI_TO_TCHAR(__FUNCTION__)


namespace Helper
{
	template<typename TEnum>
	FString EnumToString( const FString& name, TEnum value )
	{
		const UEnum* enumPtr = FindObject<UEnum>( (UPackage*)-1, *name, true );
		if( !enumPtr )
		{
			return FString( "Invalid" );
		}

		return enumPtr->GetNameStringByValue( static_cast<int64>(value) );
	}
}

#define P_ENUM_TO_STRING( Enum, value ) \
	Helper::EnumToString<Enum>( #Enum, value )
