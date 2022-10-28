// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "TTHUD.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FOnClickedSpawnTurtleButton, int);

class UTTMainWidget;
UCLASS()
class TURTLETEST_API ATTHUD : public AHUD
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

	FOnClickedSpawnTurtleButton GetOnClickedSpawnTurtleButton() const;
	FOnClickedSpawnTurtleButton& GetOnClickedSpawnTurtleButton();

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Widget")
	TSubclassOf<class UTTMainWidget> MainWidgetTemplate;

	FOnClickedSpawnTurtleButton OnClickedSpawnTurtleButton;

private:
	void InitWidgets();

	UPROPERTY()
	UTTMainWidget* MainWidget;
};
