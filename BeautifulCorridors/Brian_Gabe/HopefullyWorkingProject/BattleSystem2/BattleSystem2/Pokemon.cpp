#include "Pokemon.h"

Pokemon::~Pokemon()
{
	for (auto i : mpMoveList)
		delete i;
}

void Pokemon::useMove(int index, Pokemon* target)
{
	// Can they actually use the move?
	if (mpMoveList[index]->mPP <= 0) { return; }

	// Will the move hit?
	// check the accuracy, calculate if hit is success
	if (mpMoveList[index]->mAccuracy >= randomNumber(MIN_ACCURACY, MAX_RAND_NUM))
	{
		// Calculate the damage and apply to other
		doDamage(mpMoveList[index], target);
		// reduce the PP of the move
		--mpMoveList[index]->mPP;
		if (mpMoveList[index]->mPP <= 0)
			mpMoveList[index]->mPP = 0;
	}
	else
		return;
}

void Pokemon::doDamage(Move* move, Pokemon* Other)
{
	int damage;
	float weakness = 0;
	float STAB_MULT = 1;

	// Random number between 85 and 100
	float randNumber = randomNumber(MIN_RAND_NUM, MAX_RAND_NUM);

	// Check the move used
	// What's it's power?
	// Is it the same type as the Pokemon using it?
	if (move->mType == mType[0] || move->mType == mType[1])
		STAB_MULT = 1.5f;
	else
		STAB_MULT = 1;
	// Is the Other Pokemon weak or resistant?

	//((((2 * Level / 5 + 2) * AttackStat * AttackPower / DefenseStat) / 50) + 2) * STAB * Weakness / Resistance * RandomNumber / 100
	if (move->isSpecial)
		damage = ((((2 * LEVEL / 5 + 2) * getSpAttack() * move->mPower / getSpDefense()) / 50) + 2) * STAB_MULT * weakness * randNumber / 100;
	else
		damage = ((((2 * LEVEL / 5 + 2) * getAttack() * move->mPower / getDefense()) / 50) + 2) * STAB_MULT * weakness * randNumber / 100;

	Other->modifyHealth(damage);
}

int Pokemon::randomNumber(int min, int max)
{
	return min + (rand() % static_cast<int>(max - min + 1));
}
