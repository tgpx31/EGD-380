// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../Pokemon_C++/Type.h"
#include "GameFramework/Actor.h"
#include "Attack.generated.h"

UENUM(BlueprintType)
enum class MoveAction : uint8
{
	no_action UMETA(DisplayName = "No Action"),
	damage  UMETA(DisplayName = "Damage"),
	heal  UMETA(DisplayName = "Heal"),
	stat_change  UMETA(DisplayName = "State Change")
};

UENUM(BlueprintType)
enum class Type : uint8
{
	normal = 0,
	fighting = 1,
	flying = 2,
	poison = 3,
	ground = 4,
	rock = 5,
	bug = 6,
	ghost = 7,
	fire = 8,
	water = 9,
	grass = 10,
	electric = 11,
	psychic = 12,
	ice = 13,
	dragon = 14,
	dark = 15,
	NONE = 16
};


UCLASS()
class VR_FINALPROJECT_API AAttack : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAttack();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
		FText mName;

	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
		Type mType;

	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
		MoveAction mMoveAction = MoveAction::damage;

	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
		int32 mAffectedStatIndex = 0;

	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
		float mStatMultiplier = 0;

	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
		int32 mPower;

	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
		int32 mAccuracy;

	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
		int32 mPP;

	UPROPERTY(Category = Gameplay, EditAnywhere, BlueprintReadWrite)
		bool isSpecial;

	
};
