// Fill out your copyright notice in the Description page of Project Settings.

#include "VR_FinalProject.h"
#include "BattleManager.h"


// Sets default values
ABattleManager::ABattleManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	mUpdating = true;
	mCurrentEnemy = 0;
}

// Called when the game starts or when spawned
void ABattleManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABattleManager::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	if (mUpdating)
	{
		GLog->Log(mpPlayer1->getPokemon()->mName.ToString() + " vs " + mEnemyList[mCurrentEnemy]->mName.ToString() + "!");
		mUpdating = false;

		mpPlayer1->promptInput();
	}

	if (mpPlayer1->mAttack)
	{
		player1Attack();
		mpPlayer1->resetBools();

		//do ai player stuff here
		mUpdating = true;
	}
}

void ABattleManager::player1Attack()
{
	mpPlayer1->attack(mEnemyList[mCurrentEnemy]);
}