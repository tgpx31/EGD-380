// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Type.h"

#include "GameFramework/Pawn.h"
#include "Pokemon.generated.h"

struct Move;

UCLASS()
class BEAUTIFULCORRIDOR_API APokemon : public APawn
{
	GENERATED_BODY()
public:
	APokemon();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	inline void modifyHealth(int change) { mCurrentHealth -= change; };
	inline const FString getName() { return mName; };
	inline int getHealth() { return mCurrentHealth; };
	inline int getMaxHealth() { return mMaxHealth; };
	inline bool didFaint() { return mCurrentHealth <= 0; };

	inline int getAttack() { return mAttack; };
	inline int getSpAttack() { return mSpAttack; };
	inline int getDefense() { return mDefense; };
	inline int getSpDefense() { return mSpDefense; };
	inline int getSpeed() { return mSpeed; };

	//inline Move* getMove(int moveNum) { return mpMoveList[moveNum]; };

	inline Type getType(int pos) { return mType[pos]; };

	void useMove(int index, APokemon* target);
	//void doDamage(Move* move, APokemon* Other);
	float calcResistance(Type moveType, APokemon* other);

	void displayMoveList();

protected:
	FString mName;

	int mMaxHealth;
	int mCurrentHealth;
	int mAttack;
	int mSpAttack;
	int mDefense;
	int mSpDefense;
	int mSpeed;

	//Move* mpMoveList[4];
	Type mType[2];

	const static int LEVEL = 100;
	const static int MIN_ACCURACY = 0;
	const static int MIN_RAND_NUM = 85;
	const static int MAX_RAND_NUM = 100;

};

int randomNumber(int min, int max);
