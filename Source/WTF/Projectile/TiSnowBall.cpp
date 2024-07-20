#include "TiSnowBall.h"

// Sets default values
ATiSnowBall::ATiSnowBall() :ATiProjectile()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	m_bIsOnFloor = false;

}


// Called every frame
void ATiSnowBall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (m_bIsOnFloor)
	{
		FVector Velocity = m_projectileMovementComp->Velocity;	
		float Speed = Velocity.Size();

		if (Speed >= m_minSpeedForScaling) {
			ChangeScale();
			//FVector OldScale = GetActorScale3D();
			//UE_LOG(LogTemp, Warning, TEXT("Old Scale: %s"), *OldScale.ToString());
			//SetActorScale3D(OldScale * m_ScaleMultiplier);


			//FVector NewScale = GetActorScale3D();
			//// Adjust position to ensure the actor stays above the floor
			//AdjustPositionAfterScaling(OldScale, NewScale);

			m_bIsOnFloor = false;
		}
	}



}



// Called after components have been initialized
void ATiSnowBall::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

}


void ATiSnowBall::checkIfOnFloor(AActor* Other) {
	// Check if the hit object is the floor
	if (Other->ActorHasTag(FName("Floor"))) {
		m_bIsOnFloor = true;
	}
}
