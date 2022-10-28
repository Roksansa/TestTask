// Fill out your copyright notice in the Description page of Project Settings.


#include "Controllers/TTAIController.h"
#include "Actors/TTAIMobPawn.h"

void ATTAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	ATTAIMobPawn* AICharacter = Cast<ATTAIMobPawn>(InPawn);
	if (AICharacter)
	{
		RunBehaviorTree(AICharacter->GetBehaviorTree());
	}
}
