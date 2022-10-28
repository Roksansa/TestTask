// Copyright Epic Games, Inc. All Rights Reserved.


#include "TurtleTestGameModeBase.h"

#include "Actors/TTAIMobPawn.h"
#include "Actors/TTSpawnPoint.h"
#include "Components/TTSpawnComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Actors/TTMobPawn.h"
#include "Interfaces/IPluginManager.h"

void ATurtleTestGameModeBase::StartPlay()
{
	Super::StartPlay();
	SearchSpawners();
}

void ATurtleTestGameModeBase::SearchSpawners()
{
	TArray<AActor*> Actors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), SpawnPointTemplate.Get(), Actors);
	FoundActors.Empty();
	FoundActors.Reserve(Actors.Num());
	for (AActor* Actor : Actors)
	{
		ATTSpawnPoint* Item = StaticCast<ATTSpawnPoint*>(Actor);
		if (!SpawnComponentTemplate.Get() || Item->GetComponentByClass(SpawnComponentTemplate.Get()))
		{
			FoundActors.Add(Item);
		}
	}
}

void ATurtleTestGameModeBase::SpawnObject(int RespawnType)
{
	const ETTTurtleType Type = StaticCast<ETTTurtleType>(RespawnType + 1);
	if (Type == ETTTurtleType::NONE || Type == ETTTurtleType::MAX || !TemplateObjects.Contains(Type))
	{
		return;
	}

	for (ATTSpawnPoint* SpawnPoint : FoundActors)
	{
		if (SpawnPoint->GetRespawnType() == Type)
		{
			ATTMobPawn* Mob = StaticCast<ATTMobPawn*>(SpawnPoint->GetTTSpawnComponent()->SpawnObject(TemplateObjects[Type]));
			if (Mob)
			{
				FVector RotateGoalVector = SpawnPoint->GetActorRotation().RotateVector(SpawnPoint->GetGoalLocation());
				Mob->SetGoalLocation(RotateGoalVector + SpawnPoint->GetActorLocation());
				if (ATTAIMobPawn* AIMob = StaticCast<ATTAIMobPawn*>(Mob))
				{
					AIMob->InitBlackboard();
				}
			}
		}
	}
}
