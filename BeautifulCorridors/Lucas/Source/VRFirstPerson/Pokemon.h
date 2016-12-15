// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../Pokemon_C++/Type.h"
#include "Attack.h"
#include "GameFramework/Pawn.h"
#include "Pokemon.generated.h"

const int MOVE_AMOUNT = 4;

UCLASS()
class VRFIRSTPERSON_API APokemon : public APawn
{
	GENERATED_BODY()

	private_subobject:
	class UStaticMeshComponent* StaticMeshComponent;
	class UStaticMesh* pokemonAsset;

public:
	// Sets default values for this pawn's properties
	APokemon();
	APokemon::APokemon(const FObjectInitializer& ObjectInitializer);
	void initMesh(FString filepath);
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	//virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	inline void modifyHealth(int32 change) { mCurrentHealth -= change; };
	inline void modifyStatCoefficient(int index, float multiplier) { mStatCoefficients[index] *= multiplier; };
	inline bool didFaint() { return mCurrentHealth <= 0; };
	 
	void useMove(int index, APokemon* target);
	void doDamage(AAttack* move, APokemon* Other);
	float calcResistance(Type moveType, APokemon* other);

	void displayMoveList();

	static Type getTypeFromData(int32 type);
	void setTypes(int32 type1, int32 type2);

	///* The mesh component */
	//UPROPERTY(Category = Meshes, EditAnywhere, BlueprintReadWrite)
	//class UStaticMeshComponent* PokemonMeshComponent;

	//member variables for battle
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
	FText mName;

	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
	int32 mMaxHealth;

	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
	int32 mCurrentHealth;

	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
	int32 mAttack;

	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
	int32 mSpAttack;

	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
	int32 mDefense;

	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
	int32 mSpDefense;

	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
	int32 mSpeed;

	//actor components
	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadOnly)
	TArray<AAttack*> mpMoveList;

	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadOnly)
	TArray<Type> mType;

	//used for stat buffs
	float mStatCoefficients[5] = { 1.0f,1.0f,1.0f,1.0f,1.0f };	// Does not include HP

	//const ints for battle calculations
	const static int LEVEL = 100;
	const static int MIN_ACCURACY = 0;
	const static int MIN_RAND_NUM = 85;
	const static int MAX_RAND_NUM = 100;		
};

int randomNumber(int min, int max);
