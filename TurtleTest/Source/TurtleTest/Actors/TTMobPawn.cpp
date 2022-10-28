// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/TTMobPawn.h"

// Sets default values
ATTMobPawn::ATTMobPawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ATTMobPawn::SetGoalLocation(FVector NewGoalLocation)
{
	GoalLocation = NewGoalLocation;
}

// Called when the game starts or when spawned
void ATTMobPawn::BeginPlay()
{
	StartLocation = GetActorLocation();
	Super::BeginPlay();
}

// Called every frame
void ATTMobPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
