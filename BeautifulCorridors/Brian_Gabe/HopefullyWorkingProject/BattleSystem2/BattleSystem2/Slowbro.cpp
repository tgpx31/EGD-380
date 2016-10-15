#include "Slowbro.h"

Slowbro::Slowbro()
{
	mName = "Slowbro";

	mHealth = 394;
	mAttack = 249;
	mDefense = 319;
	mSpAttack = 299;
	mSpDefense = 259;
	mSpeed = 159;

	/*moveList[0] = new Surf();
	moveList[1] = new SlackOff();
	moveList[2] = new Psychic();
	moveList[3] = new IceBeam();*/

	mType[0] = Type::water;
	mType[1] = Type::psychic;
}
