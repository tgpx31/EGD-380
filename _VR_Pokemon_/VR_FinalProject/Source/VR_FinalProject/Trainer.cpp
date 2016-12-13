// Fill out your copyright notice in the Description page of Project Settings.

#include "VR_FinalProject.h"
#include "Trainer.h"


// Sets default values
ATrainer::ATrainer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	AutoPossessPlayer = EAutoReceiveInput::Player0;

	mCurrentInput = 0;
	mCurrentPokemon = 0;
	mInputOpen = true;
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
	GLog->Log(FString::FromInt(mCurrentInput));
}


//update this to work within an update loop
void ATrainer::promptInput()
{
	GLog->Log("What will you do?\nFight[1] Switch[2]\n");

	//get input help
	if (mCurrentInput == 1) //use a move
	{
		GLog->Log("Your move: What should " + mPokemonList[mCurrentPokemon]->mName.ToString() + "do?");
		mPokemonList[mCurrentPokemon]->displayMoveList();
		//get input here
	}
	else if (mCurrentInput == 2) //switch pokemon
	{
		displayRoster();
		switchPokemon(mCurrentInput);
	}

}

void ATrainer::attack( APokemon* enemy)
{
	mPokemonList[mCurrentPokemon]->useMove(mCurrentInput, enemy);

	//probably going to put other logistics here
}

//update this to work within an update loop
void ATrainer::promptSwitch()
{
	bool exit = false;

	while (!exit)
	{
		GLog->Log("What Pokemon will you switch to?");
		displayRoster();

		//GET INPUT HERE

		if (mPokemonList[mCurrentInput]->didFaint())
		{
			GLog->Log("That Pokemon is fainted! Try again. \n");
		}
		else
		{
			exit = true;
		}
	}
}

void ATrainer::switchPokemon(int index)
{
	mCurrentPokemon = index;
	GLog->Log("You switched to " + mPokemonList[mCurrentPokemon]->GetName() + "!");
}

void ATrainer::displayRoster()
{
	for (int i = 0; i < mPokemonList.Num(); ++i)
	{
		GLog->Log(mPokemonList[i]->GetName() + " [" + FString::FromInt(i) + "]");
	}
}