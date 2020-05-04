// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "MasterblazeGameMode.h"
#include "MasterblazeHUD.h"
#include "MasterblazeCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMasterblazeGameMode::AMasterblazeGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AMasterblazeHUD::StaticClass();
}
