// Fill out your copyright notice in the Description page of Project Settings.

#include "VRFirstPerson.h"
#include "Trainer.h"


// Sets default values
ATrainer::ATrainer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	//AutoPossessPlayer = EAutoReceiveInput::Player0;

	mCurrentInput = 0;
	mCurrentPokemon = 0;

	mBeginMove = false;
	mBeginSwitch = false;
	mChooseMove = false;
	mChooseSwitch = false;

	mAttack = false;
	mSwitch = false;
}

// Called when the game starts or when spawned
void ATrainer::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ATrainer::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	//getInput();
}

// Called to bind functionality to input
void ATrainer::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

	InputComponent->BindAction("1", IE_Pressed, this, &ATrainer::optionPressed<1>);
	InputComponent->BindAction("2", IE_Pressed, this, &ATrainer::optionPressed<2>);
	InputComponent->BindAction("3", IE_Pressed, this, &ATrainer::optionPressed<3>);
	InputComponent->BindAction("4", IE_Pressed, this, &ATrainer::optionPressed<4>);
}

void ATrainer::optionPressed(int optionNum)
{
	mCurrentInput = optionNum;
	//GLog->Log(FString::FromInt(mCurrentInput));

	switch (mCurrentInput)
	{
	case 1:
		if (mChooseMove) //informs the battle manager that player attack is ready
		{
			mAttack = true;
		}
		else if (mChooseSwitch)
		{
			mSwitch = true;
		}
		else if (mBeginMove == false) //for the first stage of player decision, choosing whether to fight or switch
		{
			mBeginMove = true;
			promptMove();
			mChooseMove = true;
		}		
		break;

	case 2:
		if (mChooseMove) //informs the battle manager that player attack is ready
		{
			mAttack = true;
		}
		else if (mChooseSwitch)
		{
			mSwitch = true;
		}
		else if (mBeginSwitch == false) //for the first stage of player decision, choosing whether to fight or switch
		{
			mBeginSwitch = true;
			promptSwitch();
			mChooseSwitch = true;
		}
		break;

	case 3:
		if (mChooseMove) //informs the battle manager that player attack is ready
		{
			mAttack = true;
		}
		/*else if (mChooseSwitch)
		{
			mSwitch = true;
		}*/
		break;

	case 4:
		if (mChooseMove) //informs the battle manager that player attack is ready
		{
			mAttack = true;
		}
		/*else if (mChooseSwitch)
		{
			mSwitch = true;
		}*/
		break;

	}
}


//update this to work within an update loop
void ATrainer::promptInput()
{
	GLog->Log("What will you do?\nFight[1] Switch[2]\n");
	GLog->Log(" ");
}

void ATrainer::promptMove()
{
	GLog->Log("");
	GLog->Log("Your move: What should " + mPokemonList[mCurrentPokemon]->mName.ToString() + " do?");
	GLog->Log("");
	mPokemonList[mCurrentPokemon]->displayMoveList();
}

void ATrainer::attack( APokemon* enemy)
{
	mPokemonList[mCurrentPokemon]->useMove(mCurrentInput - 1, enemy);
	//probably going to put other logistics here
}

//update this to work within an update loop
void ATrainer::promptSwitch()
{
	GLog->Log("What Pokemon will you switch to?");
	displayActiveRoster();
}

void ATrainer::switchPokemon()
{
	//check if pokemon has fainted to prevent switch
	if (mPokemonList[!mCurrentPokemon]->didFaint())
		return;

	//dont switch if pokemon is the current one out
	if (mCurrentPokemon == mCurrentInput - 1)
		return;

	if (mCurrentPokemon == 0)
	{
		FVector up = mPokemonList[0]->GetActorLocation();
		FVector down = mPokemonList[1]->GetActorLocation();

		mPokemonList[0]->SetActorLocation(down);
		mPokemonList[1]->SetActorLocation(up);
	}
	else
	{
		FVector up = mPokemonList[1]->GetActorLocation();
		FVector down = mPokemonList[0]->GetActorLocation();

		mPokemonList[0]->SetActorLocation(up);
		mPokemonList[1]->SetActorLocation(down);
	}

	mCurrentPokemon = mCurrentInput - 1;

	GLog->Log("You switched to " + mPokemonList[mCurrentPokemon]->mName.ToString() + "!");
}

void ATrainer::switchPokemonToOther()
{
	//check if pokemon has fainted to prevent switch
	if (mPokemonList[!mCurrentPokemon]->didFaint())
		return;

	if (mCurrentPokemon == 0)
	{
		FVector up = mPokemonList[0]->GetActorLocation();
		FVector down = mPokemonList[1]->GetActorLocation();

		mPokemonList[0]->SetActorLocation(down);
		mPokemonList[1]->SetActorLocation(up);
	}
	else
	{
		FVector up = mPokemonList[1]->GetActorLocation();
		FVector down = mPokemonList[0]->GetActorLocation();

		mPokemonList[0]->SetActorLocation(up);
		mPokemonList[1]->SetActorLocation(down);
	}

	mCurrentPokemon = !mCurrentPokemon;
}

void ATrainer::resetBools()
{
	mBeginMove = false;
	mBeginSwitch = false;
	mChooseMove = false;
	mChooseSwitch = false;

	mAttack = false;
	mSwitch = false;
}

bool ATrainer::rosterDead()
{
	bool dead = true;

	for (int i = 0; i < mPokemonList.Num(); ++i)
	{
		if (!mPokemonList[i]->didFaint())
		{
			dead = false;
			break;
		}
	}

	return dead;
}

void ATrainer::displayRoster()
{
	for (int i = 0; i < mPokemonList.Num(); ++i)
	{
		GLog->Log(mPokemonList[i]->mName.ToString() + " [" + FString::FromInt(i + 1) + "]");
	}
}

void ATrainer::displayActiveRoster()
{
	for (int i = 0; i < mPokemonList.Num(); ++i)
	{
		if (!mPokemonList[i]->didFaint())
		{
			GLog->Log(mPokemonList[i]->mName.ToString() + " [" + FString::FromInt(i + 1) + "]");
		}
	}
}

FText ATrainer::getPokemonNameAtIndex(int i)
{
	return mPokemonList[i]->mName;
}

FText ATrainer::getPokemonMoveNameAtIndex(int moveIndex)
{
	return getPokemon()->mpMoveList[moveIndex]->mName;
}