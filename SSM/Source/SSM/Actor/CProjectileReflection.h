// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CProjectile.h"
#include "CProjectileReflection.generated.h"


UCLASS()
class ACProjectileReflection : public ACProjectile
{
	GENERATED_BODY()
	
public:
	ACProjectileReflection( const FObjectInitializer& ObjectInitializer );

protected:
	virtual void _OnOverlap() override;
};
