// Fill out your copyright notice in the Description page of Project Settings.

#include "ConfigEditorPluginPrivatePCH.h"
#include "ConfigEditorPlugin.h"
#include "MyConfigFactory.h"

UObject * UMyConfigFactory::FactoryCreateNew(UClass * Class, UObject * InParent, FName Name, EObjectFlags Flags, UObject * Context, FFeedbackContext * Warn)
{
	return nullptr;
}

UMyConfigFactory::UMyConfigFactory(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	bCreateNew = true;
	bEditAfterNew = true;
	bEditorImport = true;
	bText = true;
	Formats.Add(TEXT("acfg;Config File for BluePrints"));
	//ContextClass = 
	//SupportedClass = UMyObject::StaticClass();
}