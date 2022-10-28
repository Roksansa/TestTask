// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TTTypes.h"
#include "TurtleTestGameModeBase.generated.h"

class UTTSpawnComponent;
class ATTSpawnPoint;
class ATTMobPawn;

UCLASS()
class TURTLETEST_API ATurtleTestGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	virtual void StartPlay() override;
	void SpawnObject(int RespawnType);

private:
	void SearchSpawners();

	// if you need a specific spawn component, or else if null - all
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = GameInfo, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<UTTSpawnComponent> SpawnComponentTemplate;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = GameInfo, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<ATTSpawnPoint> SpawnPointTemplate;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = GameInfo, meta = (AllowPrivateAccess = "true"))
	TMap<ETTTurtleType, TSubclassOf<ATTMobPawn>> TemplateObjects;

	TArray<ATTSpawnPoint*> FoundActors;
};
