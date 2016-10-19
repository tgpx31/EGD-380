// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "Pokemon.generated.h"

UCLASS()
class BEAUTIFULCORRIDOR_API APokemon : public APawn
{
	GENERATED_BODY()
public:
	// Sets default values for this pawn's properties
	APokemon();

	//getters and setters
	inline void modifyHealth(int change) { mCurrentHealth -= change; };
	inline FText getName() { return mName; };
	inline int getHealth() { return mCurrentHealth; };
	inline int getMaxHealth() { return mMaxHealth; };
	inline bool didFaint() { return mCurrentHealth <= 0; };

	inline int getAttack() { return mAttack; };
	inline int getSpAttack() { return mSpAttack; };
	inline int getDefense() { return mDefense; };
	inline int getSpDefense() { return mSpDefense; };
	inline int getSpeed() { return mSpeed; };

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;	

private:
	FText mName;

	int mMaxHealth;
	int mCurrentHealth;
	int mAttack;
	int mSpAttack;
	int mDefense;
	int mSpDefense;
	int mSpeed;
};
