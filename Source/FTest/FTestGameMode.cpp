// Copyright Epic Games, Inc. All Rights Reserved.

#include "FTestGameMode.h"
#include "FTestCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "SpawnPoint.h"
#include "Engine/Engine.h"

AFTestGameMode::AFTestGameMode()
{
	// set default pawn class to our Blueprinted character
	/*static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprints/BP_ThirdPersonCharacter.BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}*/
}

void AFTestGameMode::Respawn(AController* Controller)
{
	if (Controller)
	{
		FVector Location = SpawnPoint->GetActorLocation();
		FRotator Rotation = SpawnPoint->GetActorRotation();
		if (APawn* Pawn = GetWorld()->SpawnActor<APawn>(DefaultPawnClass, Location, Rotation))
		{
			Controller->Possess(Pawn);
		}
		/*if (Role == ROLE_Authority)
		{
			
		}*/
	}
}

void AFTestGameMode::BeginPlay()
{
	Super::BeginPlay();


}
