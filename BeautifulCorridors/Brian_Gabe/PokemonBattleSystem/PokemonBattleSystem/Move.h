#ifndef MOVE_H
#define MOVE_H

#include <string>

#include "Type.h"

struct Move
{
	std::string mName;
	Type mType;
	int mPower;
	int mPP;

	bool isSpecial;

	Move();
	~Move();
};

#endif