// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Actors/TTMobPawn.h"
#include "AnimNotify_PlayNiagaraEffect.h"
#include "AnimNotify_TTPlayNiagaraEffect.generated.h"

/**
 * 
 */
UCLASS()
class TURTLETEST_API UAnimNotify_TTPlayNiagaraEffect : public UAnimNotify_PlayNiagaraEffect
{
	GENERATED_BODY()

public:
	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation) override;

	UPROPERTY(EditAnywhere, Category = NiagaraSystem, meta = (ToolTip = "Type for mob anim"))
	ETTEffectsType EffectType;
};
