// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TTSpawnComponent.generated.h"

class ATTMobPawn;

USTRUCT(BlueprintType)
struct FTTDataSpawnActor
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	AActor* RespawnActor;
};

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class TURTLETEST_API UTTSpawnComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UTTSpawnComponent();
	
	AActor* SpawnObject(TSubclassOf<AActor> Actor);

	virtual void BeginPlay() override;

	void SetArea(const FVector2D& Vector);
private:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = GameInfo, meta = (AllowPrivateAccess = "true"))
	FTTDataSpawnActor SpawnData;

	UPROPERTY()
	FVector2D Area;
};
