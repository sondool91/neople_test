// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "Components/ArrowComponent.h"
#include "Components/SphereComponent.h"
#include "CProjectile.generated.h"


class UProjectileMovementComponent;


USTRUCT()
struct FFireParams
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY()
	UClass* ProjectileClass;

	UPROPERTY()
	FVector Velocity;
};


UCLASS()
class ACProjectile : public AActor
{
	GENERATED_BODY()

protected:
	UPROPERTY( EditAnywhere, Category = C_Projectile, meta = (AllowPrivateAccess = "true") )
	UProjectileMovementComponent* _ProjectileMovementComponent;

	UPROPERTY( VisibleAnywhere, BlueprintReadOnly, Category = C_Projectile, meta = (AllowPrivateAccess = "true") )
	USphereComponent* _CollisionSphereComponent;

	UPROPERTY( EditAnywhere, Category = C_Projectile, meta = (AllowPrivateAccess = "true") )
	float _TimeoutRequiredSec;

	float _TimeoutRemainSec;

	FFireParams _FireParams;

public:
	ACProjectile( const FObjectInitializer& ObjectInitializer );

	static ACProjectile* Create( UWorld* world, AActor* owner, const FTransform& transform, FFireParams params );
	static FTransform MakeFireTransform( const FVector& location, 
										 const FRotator& rotation, 
										 const FVector& locationOffset );

	virtual void BeginPlay() override;
	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
	virtual void Tick( float DeltaSeconds ) override;

	void Init( const FFireParams& params, const FTransform& transform );
	
protected:
	virtual void _OnTimeout();
	virtual void _OnOverlap();
};
