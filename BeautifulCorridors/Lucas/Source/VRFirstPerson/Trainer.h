// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Pokemon.h"
#include "GameFramework/Character.h"
#include "Trainer.generated.h"

UCLASS()
class VRFIRSTPERSON_API ATrainer : public ACharacter
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

	//input handling function that sets mCurrentInput
	UFUNCTION(BlueprintCallable, Category = "Pokemon")
	void optionPressed(int optionNum);

	UFUNCTION(BlueprintCallable, Category = "Pokemon")
	FText getPokemonNameAtIndex(int i);

	UFUNCTION(BlueprintCallable, Category = "Pokemon")
	FText getPokemonMoveNameAtIndex(int moveIndex);

	template<int option>
	void optionPressed() { optionPressed(option); };

	//functions that prompt user input, may become useless later
	void promptInput();
	void promptSwitch();
	void promptMove();

	//displays info to the user
	void displayRoster();
	void displayActiveRoster();

	//general use battle fucntions
	void attack(APokemon* enemy);
	void switchPokemon();
	void switchPokemonToOther();
	inline void enterSwitchState() { mChooseMove = false; mChooseSwitch = true; };
	//inline void enterBattleState() { mBeginSwitch = false; mBeginMove = true; };
	void resetBools();

	bool rosterDead();

	inline APokemon* getPokemon() {return mPokemonList[mCurrentPokemon];};

	//keeps track of ints that designate player state
	int mCurrentInput;
	int mCurrentPokemon;

	//bools that handle input states
	bool mBeginMove;
	bool mBeginSwitch;
	bool mChooseMove;
	bool mChooseSwitch;

	//bools that communicate with the battle manager
	bool mAttack;
	bool mSwitch;

	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadOnly)
	bool mIsPlayer;

	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadOnly)
	TArray<APokemon*> mPokemonList;
};
