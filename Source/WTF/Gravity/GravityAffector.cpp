// Fill out your copyright notice in the Description page of Project Settings.


#include "GravityAffector.h"

// Sets default values
AGravityAffector::AGravityAffector()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGravityAffector::BeginPlay()
{
	Super::BeginPlay();
	
}

float AGravityAffector::GetGravityZ()
{
	float gravityZ = GetWorld()->GetGravityZ();
	return gravityZ;
}

void AGravityAffector::AddActorToMap(AActor* ActorToAdd)
{
	if (ActorToAdd)
	{
		m_affectedActorMap[ActorToAdd->GetUniqueID()] = ActorToAdd;
	}
}

void AGravityAffector::RemoveActorFromMap(AActor* ActorToAdd)
{
	if (ActorToAdd)
	{
		m_affectedActorMap.erase(ActorToAdd->GetUniqueID());
	}

}

// Called every frame
void AGravityAffector::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	for (auto pair : m_affectedActorMap)
	{

		if (UPrimitiveComponent* PrimitiveComponent = Cast<UPrimitiveComponent>(pair.second->GetRootComponent()))
		{
			if (PrimitiveComponent->IsSimulatingPhysics())
			{
				PrimitiveComponent->SetEnableGravity(false);
				float gravityScale = GetGravityZ();

				FVector gravityDirection = (pair.second->GetActorLocation()- m_OnTargetGravityActor->GetActorLocation()).GetSafeNormal();
				PrimitiveComponent->AddForce(gravityDirection * PrimitiveComponent->GetMass() * gravityScale);
			}
		}
	}

}

