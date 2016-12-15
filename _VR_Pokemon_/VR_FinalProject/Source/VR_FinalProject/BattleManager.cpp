// Fill out your copyright notice in the Description page of Project Settings.

#include "VR_FinalProject.h"
#include "BattleManager.h"


// Sets default values
ABattleManager::ABattleManager()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	mUpdating = true;
	mEmergencySwitch = false;
	mCurrentEnemy = 0;
}

// Called when the game starts or when spawned
void ABattleManager::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ABattleManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (mUpdating)
	{
		if (mEmergencySwitch) //prompt correct info depending on player situation
		{
			mpPlayer1->promptSwitch();
			mpPlayer1->enterSwitchState();
		}
		else
		{
			GLog->Log(" ");
			GLog->Log(mpPlayer1->getPokemon()->mName.ToString() + " vs " + mEnemyList[mCurrentEnemy]->mName.ToString() + "!");

			mpPlayer1->promptInput();
			GLog->Log(" ");
		}
		
		mUpdating = false;
	}

	if (mpPlayer1->mAttack) //if attack was chosen
	{
		//determine turn order
		if (isP1Faster()) 
		{
			player1Attack();
			GLog->Log(" ");

			if (!mEnemyList[mCurrentEnemy]->didFaint()) //ensures a dead pokemon isn't attacking
				player2Attack();
		}
		else
		{
			player2Attack();
			GLog->Log(" ");

			if (!mpPlayer1->getPokemon()->didFaint())
				player1Attack();
		}

		//check win/lose states
		if (isEnemyDefeated())
		{
			GLog->Log("You win!");
		}
		else if (mpPlayer1->rosterDead())
		{
			GLog->Log("You lose!");
		}
		else //continue loop
		{
			if (mpPlayer1->getPokemon()->didFaint()) //if player's pokemon fainted, choose new one
			{
				mEmergencySwitch = true;
			}

			mUpdating = true;
		}

		mpPlayer1->resetBools();
	}
	else if (mEmergencySwitch && mpPlayer1->mSwitch) //switch pokemon when new one is absolutely needed
	{
		player1Switch();
		GLog->Log(" ");

		//return back to normal game loop
		mpPlayer1->resetBools();
		mEmergencySwitch = false;
		mUpdating = true;
	}
	else if (mpPlayer1->mSwitch) //normal in turn pokemon switch
	{
		player1Switch();
		GLog->Log(" ");
		player2Attack();

		mpPlayer1->resetBools();

		//check win/lose states
		if (mpPlayer1->rosterDead())
		{
			GLog->Log("You lose!");
		}
		else //continue loop
		{
			mUpdating = true;
		}
	}
}

void ABattleManager::player1Attack()
{
	mpPlayer1->attack(mEnemyList[mCurrentEnemy]);
}

void ABattleManager::player1Switch()
{
	mpPlayer1->switchPokemon();
}

void ABattleManager::player2Attack()
{
	int move = randomNumber(0, 3);

	mEnemyList[mCurrentEnemy]->useMove(move, mpPlayer1->getPokemon());
}


bool ABattleManager::isP1Faster()
{
	if (mpPlayer1->getPokemon()->mSpeed >= mEnemyList[mCurrentEnemy]->mSpeed)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool ABattleManager::isEnemyDefeated()
{
	bool dead = true;

	for (int i = 0; i < mEnemyList.Num(); ++i)
	{
		if (!mEnemyList[i]->didFaint())
		{
			dead = false;
			break;
		}
	}

	return dead;
}