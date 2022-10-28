// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/TTSpawnComponent.h"

UTTSpawnComponent::UTTSpawnComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

AActor* UTTSpawnComponent::SpawnObject(TSubclassOf<AActor> Actor)
{
	AActor* SpawnedActor = nullptr;
	if (Actor != nullptr)
	{
		FActorSpawnParameters SpawnParameters;
		SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
		SpawnedActor = GetWorld()->SpawnActor(Actor, &SpawnData.RespawnActor->GetTransform(), SpawnParameters);
	}
	return SpawnedActor;
}

void UTTSpawnComponent::BeginPlay()
{
	Super::BeginPlay();
	if (!IsValid(SpawnData.RespawnActor))
	{
		SpawnData.RespawnActor = GetOwner();
	}
}
