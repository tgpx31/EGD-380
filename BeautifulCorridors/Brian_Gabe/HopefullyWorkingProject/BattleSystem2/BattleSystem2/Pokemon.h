#ifndef POKEMON_H
#define POKEMON_H

#include "Type.h"
#include "Move.h"

#include <string>
#include <ctime>

class Pokemon
{
public:
	~Pokemon();

	inline void modifyHealth(int change) { mHealth += change; };

	inline int getHealth() { return mHealth; };
	inline int getAttack() { return mAttack; };
	inline int getSpAttack() { return mSpAttack; };
	inline int getDefense() { return mDefense; };
	inline int getSpDefense() { return mSpDefense; };
	inline int getSpeed() { return mSpeed; };

	inline Move* getMove(int moveNum) { return mpMoveList[moveNum]; };

	inline Type getType(int pos) { return mType[pos]; };

	void useMove(int index, Pokemon* target);
	void doDamage(Move* move, Pokemon* Other);

protected:
	std::string mName;

	int mHealth;
	int mAttack;
	int mSpAttack;
	int mDefense;
	int mSpDefense;
	int mSpeed;

	Move* mpMoveList[4];
	Type mType[2];

	const static int LEVEL = 100;
	const static int MIN_RAND_NUM = 85;
	const static int MAX_RAND_NUM = 100;

	int randomNumber(int min, int max);
};

#endif