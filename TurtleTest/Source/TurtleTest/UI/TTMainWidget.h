// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TTMainWidget.generated.h"

class UTTButtonsPanelWidget;

UCLASS()
class TURTLETEST_API UTTMainWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(meta=(BindWidget))
	UTTButtonsPanelWidget* ButtonsPanelWidget;
};
