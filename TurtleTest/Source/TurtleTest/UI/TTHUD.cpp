// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/TTHUD.h"
#include "TTMainWidget.h"
#include "TurtleTestGameModeBase.h"
#include "Blueprint/UserWidget.h"
#include "Controllers/TTPlayerController.h"

void ATTHUD::BeginPlay()
{
	Super::BeginPlay();
	InitWidgets();
}

FOnClickedSpawnTurtleButton ATTHUD::GetOnClickedSpawnTurtleButton() const
{
	return OnClickedSpawnTurtleButton;
}

FOnClickedSpawnTurtleButton& ATTHUD::GetOnClickedSpawnTurtleButton()
{
	return OnClickedSpawnTurtleButton;
}

void ATTHUD::InitWidgets()
{
	if ((MainWidgetTemplate != nullptr && MainWidget == nullptr))
	{
		MainWidget = CreateWidget<UTTMainWidget>(GetWorld(), MainWidgetTemplate.Get());
		if (!IsValid(MainWidget))
		{
			return;
		}
		MainWidget->AddToViewport();
		if (ATurtleTestGameModeBase* GM = GetWorld()->GetAuthGameMode<ATurtleTestGameModeBase>())
		{
			OnClickedSpawnTurtleButton.AddUObject(GM, &ATurtleTestGameModeBase::SpawnObject);
		}
	}
}
