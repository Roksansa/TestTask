// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/TTButtonsPanelWidget.h"
#include "UI/TTHUD.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"

void UTTButtonsPanelWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	for (size_t i = 0; i < SpawnButtons.Num(); ++i)
	{
		SButton* ButtonWidget = static_cast<SButton*>(&(SpawnButtons[i]->TakeWidget().Get()));
		ButtonWidget->SetOnClicked(FOnClicked::CreateLambda([this, i]()
		{
			OnClickedSpawnButton(i);
			//For bp used
			SpawnButtons[i]->OnClicked.Broadcast();
			return FReply::Handled();
		}));
	}
	if (!HUD.IsValid())
	{
		HUD = UGameplayStatics::GetPlayerController(this, 0)->GetHUD<ATTHUD>();
	}
}

void UTTButtonsPanelWidget::OnClickedSpawnButton(int i)
{
	if (HUD.IsValid())
	{
		HUD->GetOnClickedSpawnTurtleButton().Broadcast(i);
	}
}
