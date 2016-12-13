// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Engine/StaticMeshActor.h"
#include "APokemon.generated.h"

UCLASS()
class MYPROJECT_API AAPokemon : public AActor
{
	GENERATED_UCLASS_BODY()

	private_subobject:
		class UStaticMeshComponent* StaticMeshComponent;
		class UStaticMesh* pokemonAsset;

		TArray<FString> lines;

public:	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

};