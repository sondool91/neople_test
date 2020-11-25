// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"



#include "Engine/Engine.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"


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

	
	DECLARE_DELEGATE_OneParam( FOnPostSpawned, AActor* );
	
	template<class T>
	T* SpawnActorByTransform( const UObject* worldContextObject,
							  UClass* actorClass = nullptr,
							  AActor* owner = nullptr,
							  const FTransform& transform = FTransform::Identity,
							  bool isDeferred = false,
							  FOnPostSpawned* onPostSpawned = nullptr,
							  ESpawnActorCollisionHandlingMethod collisionMethod = ESpawnActorCollisionHandlingMethod::AlwaysSpawn )
	{
		if( false == ensureMsgf( worldContextObject, TEXT( "SpawnActorByTransform() ensure(world) == false... world[%s] owner[%s] ownerWorld[%s]" ),
			*GetNameSafe( worldContextObject ), *GetNameSafe( owner ), (owner != nullptr) ? *GetNameSafe( owner->GetWorld() ) : TEXT( "null" ) ) )
			return nullptr;
		
		if( actorClass == nullptr )
			actorClass = T::StaticClass();
		
		FActorSpawnParameters spawnParams;
		spawnParams.Owner = owner;
		spawnParams.SpawnCollisionHandlingOverride = collisionMethod;
		T* newActor = nullptr;
		UWorld* checkedWorld = GEngine->GetWorldFromContextObject( worldContextObject, EGetWorldErrorMode::LogAndReturnNull );
		if( checkedWorld != nullptr )
		{
			if( isDeferred == true )
			{
				spawnParams.bDeferConstruction = true;
			}

			newActor = checkedWorld->SpawnActor<T>( actorClass, transform, spawnParams );

			if( onPostSpawned != nullptr )
			{
				onPostSpawned->ExecuteIfBound( newActor );
			}

			if( isDeferred == true )
			{
				newActor = Cast<T>( UGameplayStatics::FinishSpawningActor( newActor, transform ) );
			}
		}
		return newActor;
	}
}

#define P_ENUM_TO_STRING( Enum, value ) \
	Helper::EnumToString<Enum>( #Enum, value )
