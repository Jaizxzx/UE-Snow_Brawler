// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TiCharacter.h"
#include "TiCharacterPlayer.generated.h"

UCLASS()
class WTF_API ATiCharacterPlayer : public ATiCharacter
{
	GENERATED_BODY()
	ATiCharacterPlayer();


public:

	virtual void TakeDamage(float Damage);


protected:


private:
	
};
