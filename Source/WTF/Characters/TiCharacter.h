// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "../WTFCharacter.h"
#include "TiCharacter.generated.h"

UCLASS()
class WTF_API ATiCharacter : public AWTFCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ATiCharacter();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	virtual void TakeDamage(float Damage);

	virtual void DestroyPlayer();


public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		AActor* m_TargetGravityActor;

private:

	float m_health =100.0f;


};


