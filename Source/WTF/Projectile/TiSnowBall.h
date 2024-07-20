// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TiProjectile.h"
#include <GameFramework/ProjectileMovementComponent.h>
#include "TiSnowBall.generated.h"

UCLASS()
class WTF_API ATiSnowBall: public ATiProjectile
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATiSnowBall();

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
	
	virtual void AdjustPositionAfterScaling(const FVector& OldScale, const FVector& NewScale);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scaling")
	float m_ScaleMultiplier;

	UPROPERTY(EditAnywhere)
	float m_minSpeedForScaling = 20.0f;

private:
	// Check if projectile is on the floor
	bool m_bIsOnFloor;
	UStaticMeshComponent* m_snowballMesh;

};
