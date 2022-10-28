// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "TTMobPawn.generated.h"

UCLASS(Abstract, Blueprintable)
class TURTLETEST_API ATTMobPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATTMobPawn();

	void SetGoalLocation(FVector NewGoalLocation);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY()
	FVector GoalLocation = FVector::ZeroVector;
	UPROPERTY()
	FVector StartLocation = FVector::ZeroVector;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
