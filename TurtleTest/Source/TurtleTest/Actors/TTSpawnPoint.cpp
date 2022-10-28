// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/TTSpawnPoint.h"
#include "Components/TTSpawnComponent.h"

ATTSpawnPoint::ATTSpawnPoint(const FObjectInitializer& ObjectInitializer)
{
	SpawnComponent = CreateDefaultSubobject<UTTSpawnComponent>(TEXT("SpawnComponent"));
}


void ATTSpawnPoint::BeginPlay()
{
	Super::BeginPlay();
	check(SpawnComponent);
	SpawnComponent->SetArea(SpawnArea);
}

ETTTurtleType ATTSpawnPoint::GetRespawnType() const
{
	return RespawnType;
}

UTTSpawnComponent* ATTSpawnPoint::GetTTSpawnComponent()
{
	return SpawnComponent;
}

FVector ATTSpawnPoint::GetGoalLocation() const
{
	return GoalLocation;
}
