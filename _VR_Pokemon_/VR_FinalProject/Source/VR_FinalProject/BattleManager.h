// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
/**
 * 
 */

#include "Pokemon.h"

enum BattleState
{
	player1Switch,
	player1Attack,
	player2Switch,
	player2Attack
};

class VR_FINALPROJECT_API BattleManager
{
public:
	BattleManager();
	~BattleManager();

};
