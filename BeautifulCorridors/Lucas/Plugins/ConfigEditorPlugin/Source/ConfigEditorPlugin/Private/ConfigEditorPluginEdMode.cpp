// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "ConfigEditorPluginPrivatePCH.h"
#include "ConfigEditorPluginEdMode.h"
#include "ConfigEditorPluginEdModeToolkit.h"
#include "Toolkits/ToolkitManager.h"

const FEditorModeID FConfigEditorPluginEdMode::EM_ConfigEditorPluginEdModeId = TEXT("EM_ConfigEditorPluginEdMode");

FConfigEditorPluginEdMode::FConfigEditorPluginEdMode()
{

}

FConfigEditorPluginEdMode::~FConfigEditorPluginEdMode()
{

}

void FConfigEditorPluginEdMode::Enter()
{
	FEdMode::Enter();

	if (!Toolkit.IsValid() && UsesToolkits())
	{
		Toolkit = MakeShareable(new FConfigEditorPluginEdModeToolkit);
		Toolkit->Init(Owner->GetToolkitHost());
	}
}

void FConfigEditorPluginEdMode::Exit()
{
	if (Toolkit.IsValid())
	{
		FToolkitManager::Get().CloseToolkit(Toolkit.ToSharedRef());
		Toolkit.Reset();
	}

	// Call base Exit method to ensure proper cleanup
	FEdMode::Exit();
}

bool FConfigEditorPluginEdMode::UsesToolkits() const
{
	return true;
}




