// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "SlateBasics.h"
#include "ConfigImport2Style.h"

class FConfigImport2Commands : public TCommands<FConfigImport2Commands>
{
public:

	FConfigImport2Commands()
		: TCommands<FConfigImport2Commands>(TEXT("ConfigImport2"), NSLOCTEXT("Contexts", "ConfigImport2", "ConfigImport2 Plugin"), NAME_None, FConfigImport2Style::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr< FUICommandInfo > PluginAction;
};
