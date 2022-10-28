// Fill out your copyright notice in the Description page of Project Settings.


#include "Animations/Notifies/AnimNotify_TTPlayNiagaraEffect.h"

#include "Actors/TTMobPawn.h"

void UAnimNotify_TTPlayNiagaraEffect::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	ATTMobPawn* Mob = Cast<ATTMobPawn>(MeshComp->GetOwner());
	if (Mob)
	{
		Template = Mob->GetNiagaraSystem(EffectType);
	}
	Super::Notify(MeshComp, Animation);
}
