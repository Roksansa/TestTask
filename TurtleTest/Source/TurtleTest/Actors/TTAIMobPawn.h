// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/TTMobPawn.h"
#include "TTAIMobPawn.generated.h"

class UBehaviorTree;

UCLASS()
class TURTLETEST_API ATTAIMobPawn : public ATTMobPawn
{
	GENERATED_BODY()

public:
	UBehaviorTree* GetBehaviorTree();
	void InitBlackboard();

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="AI")
	UBehaviorTree* BehaviorTree;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="AI")
	FName KeyNameGoal;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="AI")
	FName KeyNameStart;
};
