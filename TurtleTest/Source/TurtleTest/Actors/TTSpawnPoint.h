// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TTTypes.h"
#include "TTSpawnPoint.generated.h"

class UTTSpawnComponent;
class UNiagaraSystem;

UCLASS()
class TURTLETEST_API ATTSpawnPoint : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ATTSpawnPoint(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

	ETTTurtleType GetRespawnType() const;
	UTTSpawnComponent* GetTTSpawnComponent();
	FVector GetGoalLocation() const;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = GameInfo, meta = (AllowPrivateAccess = "true"))
	UTTSpawnComponent* SpawnComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = GameInfo, meta = (AllowPrivateAccess = "true"))
	ETTTurtleType RespawnType;
	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = GameInfo, meta = (AllowPrivateAccess = "true", MakeEditWidget))
	FVector GoalLocation;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "VFX", meta = (AllowPrivateAccess = "true"))
	UNiagaraSystem* Effect;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = GameInfo, meta = (AllowPrivateAccess = "true", MakeEditWidget))
	FVector2D SpawnArea = FVector2D(100,100);
};
