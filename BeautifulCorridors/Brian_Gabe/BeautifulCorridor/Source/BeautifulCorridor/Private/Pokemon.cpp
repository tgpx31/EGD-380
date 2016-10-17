// Fill out your copyright notice in the Description page of Project Settings.

#include "BeautifulCorridor.h"
#include "Pokemon.h"


// Sets default values
APokemon::APokemon()
{
	
	UPROPERTY(EditAnywhere)
	FSphere tempModel;

 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APokemon::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APokemon::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void APokemon::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

