// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include <GameFramework/ProjectileMovementComponent.h>
#include "TiProjectile.generated.h"


class ATiCharacter;

UCLASS()
class WTF_API ATiProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATiProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Override PostInitializeComponents
	virtual void OnConstruction(const FTransform& Transform) override;

	// Called when the projectile hits something
	virtual void NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit) override;


	virtual void DealDamage(ATiCharacter* CharacterActor);

	virtual void DestroyProjectile();

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile")
		int m_ProjectileSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile")
		int m_Damage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile")
		int m_Lifetime;
	

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Movement")
	UProjectileMovementComponent* m_projectileMovementComp;


private:

	float m_timeSinceSpawn;
};
