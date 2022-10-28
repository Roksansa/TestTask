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
		SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;

		FTransform Transform = SpawnData.RespawnActor->GetTransform();
		const FVector OffsetLoc = FVector(FMath::RandRange(-Area.X, Area.X), FMath::RandRange(-Area.Y, Area.Y), 0);
		Transform.SetLocation(Transform.GetLocation() + OffsetLoc);
		SpawnedActor = GetWorld()->SpawnActor(Actor, &Transform, SpawnParameters);
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

void UTTSpawnComponent::SetArea(const FVector2D& Vector)
{
	Area = Vector;
}
