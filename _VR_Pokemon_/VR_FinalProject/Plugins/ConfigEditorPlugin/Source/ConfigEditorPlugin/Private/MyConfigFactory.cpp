// Fill out your copyright notice in the Description page of Project Settings.

#include "ConfigEditorPluginPrivatePCH.h"
#include "ConfigEditorPlugin.h"
#include "MyConfigFactory.h"
#include "Pokemon.h"

UObject * UMyConfigFactory::FactoryCreateNew(UClass * Class, UObject * InParent, FName Name, EObjectFlags Flags, UObject * Context, FFeedbackContext * Warn)
{
	APokemon* newPokemon = NewObject<APokemon>(InParent, Name, Flags, Context);
	return newPokemon;
}

UMyConfigFactory::UMyConfigFactory(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	//bCreateNew = true;
	//bEditAfterNew = true;
	//bEditorImport = true;
	bText = true;
	Formats.Add(TEXT("acfg;Config file for BluePrints"));
	
	//TSubclassOf <APokemon> ContextClass;
	SupportedClass = APokemon::StaticClass();//TSubclassOf <APokemon> SupportedClass;
}