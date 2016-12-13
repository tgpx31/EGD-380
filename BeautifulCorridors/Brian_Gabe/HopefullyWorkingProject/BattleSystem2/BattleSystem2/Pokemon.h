#ifndef POKEMON_H
#define POKEMON_H

#include "Type.h"
#include "Move.h"

#include <iostream>
#include <string>
#include <ctime>

class Pokemon
{
public:
	~Pokemon();

	inline void modifyHealth(int change) { mCurrentHealth -= change; };
	inline void modifyStatCoefficient(int index, float multiplier) { mStatCoefficients[index] *= multiplier; };
	inline bool didFaint() { return mCurrentHealth <= 0; };
	std::string getStat(int id);
	
	inline const std::string getName() { return mName; };
	inline int getHealth() { return mCurrentHealth; };
	inline int getMaxHealth() { return mMaxHealth; };
	inline int getAttack() { return static_cast<int>(mAttack * mStatCoefficients[0]); };
	inline int getSpAttack() { return static_cast<int>(mSpAttack * mStatCoefficients[2]); };
	inline int getDefense() { return static_cast<int>(mDefense * mStatCoefficients[1]); };
	inline int getSpDefense() { return static_cast<int>(mSpDefense * mStatCoefficients[3]); };
	inline int getSpeed() { return static_cast<int>(mSpeed * mStatCoefficients[4]); };

	inline Move* getMove(int moveNum) { return mpMoveList[moveNum]; };
	inline Type getType(int pos) { return mType[pos]; };

	void useMove(int index, Pokemon* target);
	void doDamage(Move* move, Pokemon* Other);
	float calcResistance(Type moveType, Pokemon* other);

	void displayMoveList();

protected:
	std::string mName;

	int mMaxHealth;
	int mCurrentHealth;
	int mAttack;
	int mSpAttack;
	int mDefense;
	int mSpDefense;
	int mSpeed;

	float mStatCoefficients[5] = { 1.0f,1.0f,1.0f,1.0f,1.0f };	// Does not include HP

	Move* mpMoveList[4];
	Type mType[2];

	const static int LEVEL = 100;
	const static int MIN_ACCURACY = 0;
	const static int MIN_RAND_NUM = 85;
	const static int MAX_RAND_NUM = 100;
};
int randomNumber(int min, int max);

#endif