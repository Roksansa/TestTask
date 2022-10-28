// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "TTMobPawn.generated.h"

UENUM(BlueprintType)
enum class ETTEffectsType : uint8
{
	NONE,
	Spawn,
	GoalDone,
	MAX
};

class UNiagaraSystem;

DECLARE_MULTICAST_DELEGATE_OneParam(FChangeOnSpawnTime, bool);

UCLASS(Abstract, Blueprintable)
class TURTLETEST_API ATTMobPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATTMobPawn();

	void SetGoalLocation(FVector NewGoalLocation);
	UNiagaraSystem* GetNiagaraSystem(ETTEffectsType Type) const;
	UFUNCTION(BlueprintCallable)
	void SetGoalDone(bool bDone);
	UFUNCTION(BlueprintCallable)
	bool GetGoalDone() const;
	UFUNCTION(BlueprintCallable)
	void SetOnSpawnTime(bool bDone);
	bool GetOnSpawnTime() const;

	FChangeOnSpawnTime& GetChangeOnSpawnTime();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY()
	FVector GoalLocation = FVector::ZeroVector;
	UPROPERTY()
	FVector StartLocation = FVector::ZeroVector;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "VFX")
	TMap<ETTEffectsType, UNiagaraSystem*> Effects;
	
	bool bGoalDone = false;
	bool bOnSpawnTime = false;
};
