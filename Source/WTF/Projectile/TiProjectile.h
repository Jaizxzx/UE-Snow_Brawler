// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include <GameFramework/ProjectileMovementComponent.h>
#include "TiProjectile.generated.h"

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
