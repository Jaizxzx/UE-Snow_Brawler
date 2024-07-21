// Fill out your copyright notice in the Description page of Project Settings.


#include "TiProjectile.h"
#include "TiCharacter.h"

// Sets default values
ATiProjectile::ATiProjectile()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	m_projectileMovementComp = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
	if (m_projectileMovementComp)
	{
		m_projectileMovementComp->bAutoActivate = true; // Automatically activate the component

		m_projectileMovementComp->bRotationFollowsVelocity = true; // Rotate the projectile to follow its velocity
		m_projectileMovementComp->bShouldBounce = true; // Whether the projectile should bounce
	}

	m_timeSinceSpawn = 0;

}

// Called when the game starts or when spawned
void ATiProjectile::BeginPlay()
{
	Super::BeginPlay();


	// Update the projectile movement component's speed using the value set in the editor
	m_projectileMovementComp->InitialSpeed = m_ProjectileSpeed;

}

// Called every frame
void ATiProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	m_timeSinceSpawn += DeltaTime;

	if (m_timeSinceSpawn> m_Lifetime)
	{
		DestroyProjectile();

	}
}


// Called after components have been initialized
void ATiProjectile::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	// Ensure that the projectile movement component uses the speed set in the editor
	m_projectileMovementComp->InitialSpeed = m_ProjectileSpeed;

}


// Called when the projectile hits something
void ATiProjectile::NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	Super::NotifyHit(MyComp, Other, OtherComp, bSelfMoved, HitLocation, HitNormal, NormalImpulse, Hit);
	
	//Check if the hit Actor is of TiCharacter class

	ATiCharacter* characterActor = Cast<ATiCharacter>(Other);

	if (characterActor)
	{
		DealDamage(characterActor);
	}
}

void ATiProjectile::DealDamage(ATiCharacter* CharacterActor)
{
	DestroyProjectile();
	if (CharacterActor)
	{
		CharacterActor->TakeDamage(m_Damage);
	}

}

void ATiProjectile::DestroyProjectile()
{
	Destroy();
}
