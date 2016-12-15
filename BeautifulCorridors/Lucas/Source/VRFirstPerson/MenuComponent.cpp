// Fill out your copyright notice in the Description page of Project Settings.

#include "VRFirstPerson.h"
#include "MenuComponent.h"


// Sets default values for this component's properties
UMenuComponent::UMenuComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;
	setMenuState(EMenuState::MENU_STATE_RIGHT);
	setMenuScreen(EMenuScreens::MENU_SCREEN_BASE);
	// ...
}


// Called when the game starts
void UMenuComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UMenuComponent::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ...
}

//Processing when the player presses enter on the menu
void UMenuComponent::processEnterPress()
{
	//Depending on what screen of the menu that the player is on
	switch (mEMenuScreen)
	{
		//If it's on the main screen
	case EMenuScreens::MENU_SCREEN_BASE:
		switch (mEMenuState)
		{
		case EMenuState::MENU_STATE_LEFT:
			mEMenuScreen = EMenuScreens::MENU_SCREEN_MOVES;
			break;
		case EMenuState::MENU_STATE_RIGHT:
			mEMenuScreen = EMenuScreens::MENU_SCREEN_POKEMON;
			break;
		}
		break;
	case EMenuScreens::MENU_SCREEN_MOVES:
		switch (mEMenuState)
		{
		case EMenuState::MENU_STATE_LEFT:
			break;
		case EMenuState::MENU_STATE_RIGHT:
			break;
		case EMenuState::MENU_STATE_BOTTOM:
			break;
		case EMenuState::MENU_STATE_TOP:
			break;
		}
		break;
	case EMenuScreens::MENU_SCREEN_POKEMON:
		switch (mEMenuState)
		{
		case EMenuState::MENU_STATE_LEFT:
			break;
		case EMenuState::MENU_STATE_RIGHT:
			break;
		case EMenuState::MENU_STATE_BOTTOM:
			break;
		case EMenuState::MENU_STATE_TOP:
			break;
		}
		break;
	}
}

void UMenuComponent::processEscapePress()
{
	switch (mEMenuScreen)
	{
	case EMenuScreens::MENU_SCREEN_MOVES:
		mEMenuScreen = EMenuScreens::MENU_SCREEN_BASE;
		break;
	case EMenuScreens::MENU_SCREEN_POKEMON:
		mEMenuScreen = EMenuScreens::MENU_SCREEN_BASE;
		break;
	}
}