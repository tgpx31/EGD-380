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
	MENU_STATE_BOTTOM UMETA(DisplayName = "Bottom"),
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
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

	UFUNCTION(BlueprintCallable, category="Enum")
		EMenuState getMenuState() { return mEMenuState; };
	

private:
	EMenuState mEMenuState;
};
