// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Type.h"
/**
 * 
 */
struct Move
{
	FString mName;
	Type mType;
	int mPower;
	int mAccuracy;
	int mPP;

	bool isSpecial;
};
