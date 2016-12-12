// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Trainer.h"
#include "GameFramework/GameMode.h"
#include "GameModeTest.generated.h"

/**
 * 
 */
UCLASS()
class VR_FINALPROJECT_API AGameModeTest : public AGameMode
{
	GENERATED_BODY()
	
public:
	virtual void Tick(float DeltaSeconds) override;
	
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadOnly)
	ATrainer* mpTrainer1;
	
};
