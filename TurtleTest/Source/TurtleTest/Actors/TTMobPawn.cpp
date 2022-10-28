// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/TTMobPawn.h"

ATTMobPawn::ATTMobPawn()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ATTMobPawn::SetGoalLocation(FVector NewGoalLocation)
{
	GoalLocation = NewGoalLocation;
}

UNiagaraSystem* ATTMobPawn::GetNiagaraSystem(ETTEffectsType Type) const
{
	return Effects.Contains(Type) ? Effects[Type] : nullptr;
}

void ATTMobPawn::SetGoalDone(bool bDone)
{
	bGoalDone = bDone;
}

bool ATTMobPawn::GetGoalDone() const
{
	return bGoalDone;
}

void ATTMobPawn::SetOnSpawnTime(bool bDone)
{
	bOnSpawnTime = bDone;
}

bool ATTMobPawn::GetOnSpawnTime() const
{
	return bOnSpawnTime;
}

void ATTMobPawn::BeginPlay()
{
	StartLocation = GetActorLocation();
	Super::BeginPlay();
	SetOnSpawnTime(false);
}
