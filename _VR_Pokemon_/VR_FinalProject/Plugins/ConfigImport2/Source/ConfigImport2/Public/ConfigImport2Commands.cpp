// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "ConfigImport2PrivatePCH.h"
#include "ConfigImport2Commands.h"

#define LOCTEXT_NAMESPACE "FConfigImport2Module"

void FConfigImport2Commands::RegisterCommands()
{
	UI_COMMAND(PluginAction, "ConfigImport2", "Execute ConfigImport2 action", EUserInterfaceActionType::Button, FInputGesture());
}

#undef LOCTEXT_NAMESPACE
