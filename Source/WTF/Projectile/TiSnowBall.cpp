#include "TiSnowBall.h"

// Sets default values
ATiSnowBall::ATiSnowBall() :ATiProjectile()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	m_bIsOnFloor = false;

	

}

// Called when the game starts or when spawned
void ATiSnowBall::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ATiSnowBall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (m_bIsOnFloor)
	{
		if (m_snowballMesh)
		{
			FVector Velocity = m_snowballMesh->GetComponentVelocity();
			float Speed = Velocity.Size();

			if (Speed >= m_minSpeedForScaling)
			{

				FVector OldScale = GetActorScale3D();
				SetActorScale3D(OldScale * m_ScaleMultiplier);


				FVector NewScale = GetActorScale3D();
				// Adjust position to ensure the actor stays above the floor
				AdjustPositionAfterScaling(OldScale, NewScale);

				m_bIsOnFloor = false;
			}
		}
	}



}


void ATiSnowBall::AdjustPositionAfterScaling(const FVector& OldScale, const FVector& NewScale)
{
	FVector CurrentLocation = GetActorLocation();

	// Calculate the height difference
	float HeightDifference = (NewScale.Z - OldScale.Z) * 0.5f;

	// Adjust the actor’s position
	FVector NewLocation = CurrentLocation + FVector(0.0f, 0.0f, HeightDifference);
	SetActorLocation(NewLocation);
}


// Called after components have been initialized
void ATiSnowBall::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	m_snowballMesh = GetComponentByClass<UStaticMeshComponent>();
	if (m_snowballMesh)
	{
		// Set collision properties
		m_snowballMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
		m_snowballMesh->SetCollisionResponseToAllChannels(ECR_Block);
		m_snowballMesh->SetNotifyRigidBodyCollision(true);
	}

}


// Called when the projectile hits something
void ATiSnowBall::NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	Super::NotifyHit(MyComp, Other, OtherComp, bSelfMoved, HitLocation, HitNormal, NormalImpulse, Hit);
	for (auto tag : Other->Tags)
	{
		UE_LOG(LogTemp, Warning, TEXT("Tag on hit actor: %s"), *tag.ToString());
	}

	// Check if the hit object is the floor
	if (Other->ActorHasTag(FName("Floor")))
	{
		m_bIsOnFloor = true;
	}
}
