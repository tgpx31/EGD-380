// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "MenuComponent.generated.h"

UENUM(BlueprintType)
enum class EMenuState : uint8
{
	MENU_STATE_LEFT UMETA(DisplayName="Left"),
	MENU_STATE_RIGHT UMETA(DisplayName = "Right"),
	MENU_STATE_TOP UMETA(DisplayName = "Top"),
	MENU_STATE_BOTTOM UMETA(DisplayName = "Bottom")
};

UENUM(BlueprintType)
enum class EMenuScreens : uint8
{
	MENU_SCREEN_BASE UMETA(DisplayName="Base"),
	MENU_SCREEN_MOVES UMETA(DisplayName="Moves"),
	MENU_SCREEN_POKEMON UMETA(DisplayName="Pokemon")
};

UCLASS(meta=(BlueprintSpawnableComponent) )
class VRFIRSTPERSON_API UMenuComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMenuComponent();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	//Accessors and setters
	UFUNCTION(BlueprintCallable, category="Enum")
		EMenuState getMenuState() { return mEMenuState; };
	
	UFUNCTION(BlueprintCallable, category = "Enum")
		void setMenuState(EMenuState menuState) { mEMenuState = menuState; };

	UFUNCTION(BlueprintCallable, category = "Enum")
		EMenuScreens getMenuScreen() { return mEMenuScreen; };

	UFUNCTION(BlueprintCallable, category = "Enum")
		void setMenuScreen(EMenuScreens menuScreen) { mEMenuScreen = menuScreen; };

private:
	EMenuState mEMenuState;
	EMenuScreens mEMenuScreen;
};
