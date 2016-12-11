// Fill out your copyright notice in the Description page of Project Settings.

#include "VR_FinalProject.h"
#include "Trainer.h"


// Sets default values
ATrainer::ATrainer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

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
	getInput();
}

// Called to bind functionality to input
void ATrainer::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

void ATrainer::getInput()
{
	GLog->Log("What will you do?\nFight[0] Switch[1]\n");
	//get input here
}

void ATrainer::attack()
{

}