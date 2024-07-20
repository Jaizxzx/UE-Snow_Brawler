// Fill out your copyright notice in the Description page of Project Settings.


#include "TiCharacter.h"

// Sets default values
ATiCharacter::ATiCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATiCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATiCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (m_health <= 0)
	{
		DestroyPlayer();
	}

}

// Called to bind functionality to input
void ATiCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATiCharacter::TakeDamage(float Damage)
{
	m_health -= Damage;
}

void ATiCharacter::DestroyPlayer()
{
	Destroy();
}





