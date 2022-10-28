// Fill out your copyright notice in the Description page of Project Settings.


#include "Animations/TTMobAnimInstance.h"

#include "Actors/TTMobPawn.h"
#include "GameFramework/FloatingPawnMovement.h"

void UTTMobAnimInstance::NativeBeginPlay()
{
	Super::NativeBeginPlay();
	checkf(TryGetPawnOwner()->IsA<ATTMobPawn>(), TEXT("UTTMobAnimInstance::NativeBeginPlay() work with only ATTMobPawn and him child"));
	CurrentMob = StaticCast<ATTMobPawn*>(TryGetPawnOwner());
}

void UTTMobAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	if (!CurrentMob.IsValid())
	{
		return;
	}

	const UFloatingPawnMovement* MovComponent = StaticCast<UFloatingPawnMovement*>(CurrentMob->GetMovementComponent());
	Speed = MovComponent->Velocity.Size();
}
