// Copyright Epic Games, Inc. All Rights Reserved.

#include "CProjectile.h"
#include "GameFramework/ProjectileMovementComponent.h"


ACProjectile::ACProjectile( const FObjectInitializer& ObjectInitializer )
	: Super( ObjectInitializer )
	, _TimeoutRequiredSec( 3.f )
	, _TimeoutRemainSec( -1.f )
{
	_ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>( TEXT( "ProjectileMovementComponent" ) );
	_ProjectileMovementComponent->InitialSpeed = 5000.f;
	_ProjectileMovementComponent->bRotationFollowsVelocity = true;

	_CollisionSphereComponent = CreateDefaultSubobject<USphereComponent>( TEXT( "CollisionSphereComponent" ) );
	_CollisionSphereComponent->SetEnableGravity( false );
	_CollisionSphereComponent->CanCharacterStepUpOn = ECB_No;

	RootComponent = _CollisionSphereComponent;

	PrimaryActorTick.bCanEverTick = true;
}

ACProjectile* ACProjectile::Create( UWorld* world, AActor* owner, const FTransform& transform, FFireParams params )
{
	auto* projectile = Helper::SpawnActorByTransform<ACProjectile>( world,
																	params.ProjectileClass,
																	owner,
																	transform );
	if( IsValid( projectile ) == false )
	{
		UE_LOG( LogSSM, Warning, TEXT( "[%s] Cannot Fire~! Name[%s]" ), P_FUNCTION, *GetNameSafe( owner ) );
		return nullptr;
	}

	projectile->Init( params, transform );
	return projectile;
}

FTransform ACProjectile::MakeFireTransform( const FVector& location, 
											const FRotator& rotation,
											const FVector& locationOffset )
{
	FVector rotationVec = rotation.Vector();

	FVector startLoc = location;
	startLoc.Z += locationOffset.Z;
	startLoc = rotationVec * locationOffset.Y + startLoc;

	FTransform fireTransform = FTransform( rotation, startLoc );
	return fireTransform;
}

void ACProjectile::BeginPlay()
{
	Super::BeginPlay();

	auto* shapeComp = Cast<UShapeComponent>( GetComponentByClass( UShapeComponent::StaticClass() ) );
	if( IsValid( shapeComp ) == true )
		shapeComp->IgnoreActorWhenMoving( GetOwner(), true );

	_TimeoutRemainSec = _TimeoutRequiredSec;
}

void ACProjectile::NotifyActorBeginOverlap(AActor* OtherActor)
{
	if( IsValid( OtherActor ) == false )
		return;
	if( OtherActor == GetOwner() )
		return;
	
	Super::NotifyActorBeginOverlap( OtherActor );

	auto collisionResponse = OtherActor->GetComponentsCollisionResponseToChannel( ECC_Pawn );
	if( collisionResponse == ECR_Block )
	{
		_OnOverlap();
		UE_LOG( LogSSM, Verbose, TEXT( "[%s] this[%s] Other[%s]" ), P_FUNCTION, *GetNameSafe( this ), *GetNameSafe( OtherActor ) );
	}
}

void ACProjectile::Tick( float DeltaSeconds )
{
	Super::Tick( DeltaSeconds );

	_TimeoutRemainSec -= DeltaSeconds;
	if( _TimeoutRemainSec <= 0.f )
	{
		_OnTimeout();
	}
}

void ACProjectile::Init( const FFireParams& params, const FTransform& transform )
{
	_ProjectileMovementComponent->Velocity = params.Velocity;

	_FireParams = params;

	SetActorRotation( transform.GetRotation() );
}

void ACProjectile::_OnTimeout()
{
	Destroy();
}

void ACProjectile::_OnOverlap()
{
	Destroy();
}

