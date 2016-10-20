// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Pokemon.h"
/**
 * 
 */
struct Surf;
struct SlackOff;
struct Psychic;
struct IceBeam;

class Slowbro : public APokemon
{
public:
	Slowbro()
	{
		mName = "Slowbro";

		mMaxHealth = 394;
		mCurrentHealth = mMaxHealth;
		mAttack = 167;
		mDefense = 350;
		mSpAttack = 237;
		mSpDefense = 196;
		mSpeed = 96;

		/*mpMoveList[0] = new Surf();
		mpMoveList[1] = new SlackOff();
		mpMoveList[2] = new Psychic();
		mpMoveList[3] = new IceBeam();
*/
		mType[0] = Type::water;
		mType[1] = Type::psychic;
	};
};
