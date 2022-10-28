// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/TTAIMobPawn.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Controllers/TTAIController.h"

UBehaviorTree* ATTAIMobPawn::GetBehaviorTree()
{
	return BehaviorTree;
}

void ATTAIMobPawn::InitBlackboard()
{
	ATTAIController* AIC = GetController<ATTAIController>();
	if (AIC && AIC->GetBlackboardComponent())
	{
		AIC->GetBlackboardComponent()->SetValueAsVector(KeyNameGoal, GoalLocation + StartLocation);
		AIC->GetBlackboardComponent()->SetValueAsVector(KeyNameStart, StartLocation);
	}
}
