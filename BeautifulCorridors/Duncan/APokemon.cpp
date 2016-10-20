// Fill out your copyright notice in the Description page of Project Settings.

#include "MyProject.h"
#include "APokemon.h"
#include "Runtime/Core/Public/Misc/CoreMisc.h"
// Sets default values
AAPokemon::AAPokemon(const FObjectInitializer& ObjectInitializer)
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMeshComponent = ObjectInitializer.CreateAbstractDefaultSubobject<UStaticMeshComponent>(this, TEXT("MyMesh"));

	RootComponent = StaticMeshComponent;
}

// Called when the game starts or when spawned
void AAPokemon::BeginPlay()
{
	StaticMeshComponent->SetMobility(EComponentMobility::Movable);

	FString result = "", filePath;
	const TCHAR* delim = TEXT("\n");

	filePath = FPaths::GetPath(FPaths::GetProjectFilePath());
	filePath.AppendChars(TEXT("/Content/info.txt"), 17);

	if (!FFileHelper::LoadFileToString(result, *filePath))
	{
		//UE_LOG(LogTemp, Warning, TEXT("DIDNT OPEN FILE"));
		return;
	}

	if (result != "")
	{
		//UE_LOG(LogTemp, Warning, TEXT("string: %s"), result);
		result.ParseIntoArray(lines, delim, true);
	}
	pokemonAsset = Cast<UStaticMesh>(StaticLoadObject(UStaticMesh::StaticClass(), NULL, *lines[2]));
	StaticMeshComponent->SetStaticMesh(pokemonAsset);
	UE_LOG(LogTemp, Warning, TEXT("%s"), *lines[2]);

	StaticMeshComponent->SetWorldScale3D(FVector(FCString::Atof(*lines[0]), FCString::Atof(*lines[0]), FCString::Atof(*lines[0])));
	StaticMeshComponent->SetWorldRotation(FRotator(0.0f, 0.0f, FCString::Atof(*lines[1])));

	Super::BeginPlay();	
}

// Called every frame
void AAPokemon::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
}