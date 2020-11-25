// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CProjectile.h"
#include "CProjectileDivision.generated.h"


UCLASS()
class ACProjectileDivision : public ACProjectile
{
	GENERATED_BODY()

private:
	UPROPERTY( EditAnywhere, Category = C_Projectile, meta = (AllowPrivateAccess = true) )
	TArray<FRotator> _SplitOffsetRots;

	UPROPERTY( EditAnywhere, Category = C_Projectile, meta = (AllowPrivateAccess = true) )
	bool _DestroySelfOnSplit;

	UPROPERTY( EditAnywhere, Category = C_Projectile, meta = (AllowPrivateAccess = true) )
	int32 _SplitMaxCount;

	int32 _DivisionCurrentCount;
	
public:
	ACProjectileDivision( const FObjectInitializer& ObjectInitializer );

protected:
	virtual void _OnTimeout() override;

	void _Division();
};
