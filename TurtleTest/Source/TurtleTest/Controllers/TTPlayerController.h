// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TTPlayerController.generated.h"

UCLASS()
class TURTLETEST_API ATTPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ATTPlayerController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
};
