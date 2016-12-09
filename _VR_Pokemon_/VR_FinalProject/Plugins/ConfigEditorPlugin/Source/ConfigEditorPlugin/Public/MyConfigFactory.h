// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Factories/Factory.h"
#include "MyConfigFactory.generated.h"

/**
 * 
 */
UCLASS()
class CONFIGEDITORPLUGIN_API UMyConfigFactory : public UFactory
{
	GENERATED_BODY()
	
	// UFactory interface
	virtual UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
	// End of UFactory interface
	
};
