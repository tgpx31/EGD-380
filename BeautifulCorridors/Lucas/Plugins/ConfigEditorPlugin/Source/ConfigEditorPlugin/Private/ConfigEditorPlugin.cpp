// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "ConfigEditorPluginPrivatePCH.h"
#include "ConfigEditorPluginEdMode.h"

#define LOCTEXT_NAMESPACE "FConfigEditorPluginModule"

void FConfigEditorPluginModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	FEditorModeRegistry::Get().RegisterMode<FConfigEditorPluginEdMode>(FConfigEditorPluginEdMode::EM_ConfigEditorPluginEdModeId, LOCTEXT("ConfigEditorPluginEdModeName", "ConfigEditorPluginEdMode"), FSlateIcon(), true);
}

void FConfigEditorPluginModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	FEditorModeRegistry::Get().UnregisterMode(FConfigEditorPluginEdMode::EM_ConfigEditorPluginEdModeId);
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FConfigEditorPluginModule, ConfigEditorPlugin)