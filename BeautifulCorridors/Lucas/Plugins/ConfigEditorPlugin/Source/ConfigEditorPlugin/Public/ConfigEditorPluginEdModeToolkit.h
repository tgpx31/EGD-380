// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Editor/UnrealEd/Public/Toolkits/BaseToolkit.h"
#include "VRFirstPerson/Attack.h"

class FConfigEditorPluginEdModeToolkit : public FModeToolkit
{
public:

	FConfigEditorPluginEdModeToolkit();
	
	/** FModeToolkit interface */
	virtual void Init(const TSharedPtr<IToolkitHost>& InitToolkitHost) override;

	/** IToolkit interface */
	virtual FName GetToolkitFName() const override;
	virtual FText GetBaseToolkitName() const override;
	virtual class FEdMode* GetEditorMode() const override;
	virtual TSharedPtr<class SWidget> GetInlineContent() const override { return ToolkitWidget; }

	// FString array of Pokemon available
	TArray<TSharedPtr<FString>> Items;
	// Actual list
	TSharedPtr< SListView< TSharedPtr<FString> > > ListViewWidget;

	// Start interface
	TSharedRef<ITableRow> FConfigEditorPluginEdModeToolkit::OnGenerateRowForList(TSharedPtr<FString> Item, const TSharedRef<STableViewBase>& OwnerTable);
	// End interface

	
private:

	TSharedPtr<SWidget> ToolkitWidget;
};
