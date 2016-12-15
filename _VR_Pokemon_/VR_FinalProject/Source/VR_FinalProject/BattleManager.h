// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Trainer.h"
#include "GameFramework/Actor.h"
#include "BattleManager.generated.h"

UCLASS()
class VR_FINALPROJECT_API ABattleManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABattleManager();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	void player1Attack();
	void player1Switch();
	void player2Attack();
	void player2Switch();

	bool isP1Faster();
	bool isEnemyDefeated();

	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadOnly)
	ATrainer* mpPlayer1;

	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadOnly)
	TArray<APokemon*> mEnemyList;

	int mCurrentEnemy;

	bool mUpdating;
	bool mEmergencySwitch;
};
