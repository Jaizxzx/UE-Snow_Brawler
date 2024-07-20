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


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Override PostInitializeComponents
	virtual void OnConstruction(const FTransform& Transform) override;

	// Called when the projectile hits something in BP
	UFUNCTION(BlueprintCallable, Category = "Scaling")
	void checkIfOnFloor(AActor* Other);
	
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Scaling")
	void ChangeScale();
		
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Scaling")
	float m_ScaleMultiplier;

	UPROPERTY(EditAnywhere)
	float m_minSpeedForScaling = 20.0f;

	// Check if projectile is on the floor
	UPROPERTY(BlueprintReadOnly)
	bool m_bIsOnFloor;



};
