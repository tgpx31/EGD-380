// Fill out your copyright notice in the Description page of Project Settings.

#include "VRFirstPerson.h"
#include "BattleManager.h"


// Sets default values
ABattleManager::ABattleManager()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	mUpdating = true;
	mEmergencySwitch = false;
	mCurrentEnemy = 0;
	str = "reee eee eee eee eee eee eee \n eee eee eee eee";
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
			mpPlayer1->mPokemonList[mpPlayer1->mCurrentPokemon]->mBattleInfo = "\n\nYou win!";
		}
		else if (mpPlayer1->rosterDead())
		{
			mpPlayer1->mPokemonList[mpPlayer1->mCurrentPokemon]->mBattleInfo = "\n\nYou lose!";
		}
		else //continue loop
		{
			if (mpPlayer1->getPokemon()->didFaint()) //if player's pokemon fainted, choose new one
			{
				player1Switch();
				//mEmergencySwitch = true;
			}
			else if (mEnemyList[mCurrentEnemy]->didFaint()) //if enemy's pokemon fainted, choose new one
			{
				player2Switch();
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
			if (mpPlayer1->getPokemon()->didFaint()) //if player's pokemon fainted, choose new one
			{
				mEmergencySwitch = true;
			}

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
	mpPlayer1->switchPokemonToOther();
}

void ABattleManager::player2Attack()
{
	int move = randomNumber(0, 3);

	mEnemyList[mCurrentEnemy]->useMove(move, mpPlayer1->getPokemon());
}

void ABattleManager::player2Switch()
{
	bool exit = false;

	while (exit == false)
	{
		int num = randomNumber(0, mEnemyList.Num() - 1);

		if (!mEnemyList[num]->didFaint())
		{
			mCurrentEnemy = num;

			if (mCurrentEnemy == 0)
			{
				FVector up = mEnemyList[1]->GetActorLocation();
				FVector down = mEnemyList[0]->GetActorLocation();

				mEnemyList[1]->SetActorLocation(down);
				mEnemyList[0]->SetActorLocation(up);
			}
			else
			{
				FVector up = mEnemyList[0]->GetActorLocation();
				FVector down = mEnemyList[1]->GetActorLocation();

				mEnemyList[1]->SetActorLocation(up);
				mEnemyList[0]->SetActorLocation(down);
			}


			exit = true;
		}
	}

	GLog->Log("The enemy sent out " + mEnemyList[mCurrentEnemy]->mName.ToString() + "!");
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

void ABattleManager::setPokemon()
{
	if (mpPlayer1->mCurrentPokemon == 0)
	{
		FVector newLoc = mpPlayer1->mPokemonList[1]->GetActorLocation();
		newLoc.Z = -1220;
		mpPlayer1->mPokemonList[1]->SetActorLocation(newLoc, false);
	}
	else
	{
		FVector newLoc = mpPlayer1->mPokemonList[0]->GetActorLocation();
		newLoc.Z = -1220;
		mpPlayer1->mPokemonList[0]->SetActorLocation(newLoc, false);
	}

	if (mCurrentEnemy == 0)
	{
		FVector newLoc = mEnemyList[1]->GetActorLocation();
		newLoc.Z = -1220;
		mEnemyList[1]->SetActorLocation(newLoc, false);
	}
	else	
	{
		FVector newLoc = mEnemyList[0]->GetActorLocation();
		newLoc.Z = -1220;
		mEnemyList[0]->SetActorLocation(newLoc, false);
	}
}

void ABattleManager::switchPokemon()
{
	mpPlayer1->switchPokemonToOther();
}

void ABattleManager::setNewPokemonLocation(FVector newLoc)
{
	mpPlayer1->mPokemonList[mpPlayer1->mCurrentPokemon]->SetActorLocation(newLoc);
}