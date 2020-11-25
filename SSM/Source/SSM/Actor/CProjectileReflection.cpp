// Copyright Epic Games, Inc. All Rights Reserved.

#include "CProjectileReflection.h"

#include "GameFramework/ProjectileMovementComponent.h"


ACProjectileReflection::ACProjectileReflection( const FObjectInitializer& ObjectInitializer )
	: Super( ObjectInitializer )
{
}

void ACProjectileReflection::_OnOverlap()
{
	_ProjectileMovementComponent->Velocity = -_ProjectileMovementComponent->Velocity;
	_ProjectileMovementComponent->UpdateComponentVelocity();
}
