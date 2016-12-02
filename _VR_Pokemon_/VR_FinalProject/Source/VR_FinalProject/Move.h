// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../Pokemon_C++/Type.h"
#include "Components/ActorComponent.h"
#include "Move.generated.h"

enum MoveAction
{
	no_action = -1,
	damage = 0,
	heal = 1,
	stat_change = 2
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class VR_FINALPROJECT_API UMove : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMove();
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	FText mName;
	Type mType;

	MoveAction mMoveAction = damage;
	int32 mAffectedStatIndex = 0;
	float mStatMultiplier = 1;

	int32 mPower;
	int32 mAccuracy;
	int32 mPP;

	bool isSpecial;	
};
