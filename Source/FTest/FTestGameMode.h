// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "FTestGameMode.generated.h"

class ASpawnPoint;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnActorKilled, AActor*, VictimActor, AActor*, KillerActor, AController*, KillerController);


UCLASS(minimalapi)
class AFTestGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AFTestGameMode();

protected:
	ASpawnPoint* SpawnPoint;

public:
	void Respawn(AController* Controller);

	virtual void BeginPlay() override;

	UPROPERTY(BlueprintAssignable, Category = "GameMode")
	FOnActorKilled OnActorKilled;
};



