// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <map>
#include "GravityAffector.generated.h"

UCLASS()
class WTF_API AGravityAffector : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGravityAffector();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintPure)
	virtual float GetGravityZ();


	UFUNCTION(BlueprintCallable)
	virtual void AddActorToMap(AActor* ActorToAdd);

	UFUNCTION(BlueprintCallable)
	virtual void RemoveActorFromMap(AActor* ActorToAdd);


	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	std::map<int,AActor*> m_affectedActorMap;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		AActor* m_OnTargetGravityActor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		AActor* m_EndTargetGravityActor;


};
