// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TTButtonsPanelWidget.generated.h"

class ATTHUD;
class UButton;

UCLASS()
class TURTLETEST_API UTTButtonsPanelWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	void virtual NativeOnInitialized() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<UButton*> SpawnButtons;

private:
	void OnClickedSpawnButton(int i);

	TWeakObjectPtr<const ATTHUD> HUD;
};
