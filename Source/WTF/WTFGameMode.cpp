// Copyright Epic Games, Inc. All Rights Reserved.

#include "WTFGameMode.h"
#include "WTFCharacter.h"
#include "UObject/ConstructorHelpers.h"

AWTFGameMode::AWTFGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
