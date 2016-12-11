// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Pokemon.h"
#include "Move.h"
#include "GameFramework/Character.h"
#include "Trainer.generated.h"

UCLASS()
class VR_FINALPROJECT_API ATrainer : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ATrainer();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	void getInput();
	void attack();
	void switchPokemon(int index);
	bool rosterDead();

	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadOnly)
	TArray<APokemon*> mPokemonList;
};
