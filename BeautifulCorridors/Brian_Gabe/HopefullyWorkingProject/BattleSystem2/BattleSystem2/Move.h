#ifndef MOVE_H
#define MOVE_H

#include <string>
#include "Type.h"

enum MoveAction
{
	no_action = -1,
	damage = 0,
	heal = 1,
	stat_change = 2
};

struct Move
{
	std::string mName;
	Type mType;

	MoveAction mMoveAction = damage;
	int mAffectedStatIndex = 0;
	float mStatMultiplier = 1;

	int mPower;
	int mAccuracy;
	int mPP;

	bool isSpecial;
};

#endif