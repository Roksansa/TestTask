// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "TTMobAnimInstance.generated.h"

UCLASS()
class TURTLETEST_API UTTMobAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeBeginPlay() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Settings")
	float Speed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings")
	bool bIsGoal = false;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Settings")
	bool bIsSpawnTime = false;

private:
	TWeakObjectPtr<class ATTMobPawn> CurrentMob;
};
