// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "ConfigEditorPluginPrivatePCH.h"
#include "ModuleManager.h"

class FConfigEditorPluginModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};