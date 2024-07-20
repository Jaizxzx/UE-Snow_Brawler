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
		FVector Velocity = m_projectileMovementComp->Velocity;
		float Speed = Velocity.Size();

		if (Speed >= m_minSpeedForScaling)
		{

			// Increase the scale over time
			FVector NewScale = GetActorScale3D();
			NewScale += FVector(m_ScaleIncreaseRate * DeltaTime);
			SetActorScale3D(NewScale);
			m_bIsOnFloor = false;
		}
	}



}


// Called after components have been initialized
void ATiSnowBall::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	UStaticMeshComponent* SnowballMesh = GetComponentByClass<UStaticMeshComponent>();
	if (SnowballMesh)
	{
		// Set collision properties
		SnowballMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
		SnowballMesh->SetCollisionResponseToAllChannels(ECR_Block);
		SnowballMesh->SetNotifyRigidBodyCollision(true);
	}

}


// Called when the projectile hits something
void ATiSnowBall::NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	Super::NotifyHit(MyComp, Other, OtherComp, bSelfMoved, HitLocation, HitNormal, NormalImpulse, Hit);

	;
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
