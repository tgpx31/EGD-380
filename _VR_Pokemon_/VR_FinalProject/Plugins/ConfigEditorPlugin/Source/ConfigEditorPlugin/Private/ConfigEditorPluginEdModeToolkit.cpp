// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "ConfigEditorPluginPrivatePCH.h"
#include "ConfigEditorPluginEdMode.h"
#include "ConfigEditorPluginEdModeToolkit.h"
#include "Developer/AssetTools/Public/AssetToolsModule.h"
#include "VR_FinalProject/Pokemon.h"
#include "CoreMisc.h"

#define LOCTEXT_NAMESPACE "FConfigEditorPluginEdModeToolkit"

FConfigEditorPluginEdModeToolkit::FConfigEditorPluginEdModeToolkit()
{
	Items.Add(MakeShareable(new FString("Slowbro")));
	Items.Add(MakeShareable(new FString("Charizard")));
}

void FConfigEditorPluginEdModeToolkit::Init(const TSharedPtr<IToolkitHost>& InitToolkitHost)
{
	struct Locals
	{
		static bool IsWidgetEnabled()
		{
			return true; // GEditor->GetSelectedActors()->Num() != 0;
		}

		static FReply OnButtonClick(FVector InOffset)
		{
			//// Grab the Asset
			//IAssetTools& A_T = FModuleManager::Get().LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();
			//A_T.ImportAssets("...");
			//

			// If there is nothing that nis selected in the list, don't do anything, maybe display a warning to the user
			// If there is a pokemon selected, then create a new Pokemon BP instance
			// Open a filestream to the file fitting the pokemon that is selected
			// Load data from file into the instance
			// close the file
			// WE DID IT


			return FReply::Handled();
		}

		static TSharedRef<SWidget> MakeButton(FText InLabel, const FVector InOffset)
		{
			return SNew(SButton)
				.Text(InLabel)
				.OnClicked_Static(&Locals::OnButtonClick, InOffset);
		}
	};

	const float Factor = 256.0f;

	SAssignNew(ToolkitWidget, SBorder)
		.HAlign(HAlign_Center)
		.Padding(25)
		.IsEnabled_Static(&Locals::IsWidgetEnabled)
		[
			SNew(SVerticalBox)
			+ SVerticalBox::Slot()
			.AutoHeight()
			.HAlign(HAlign_Center)
			.Padding(50)
			[
				SNew(STextBlock)
				.AutoWrapText(true)
				.Text(LOCTEXT("HelperLabel", "Select the type of Pokemon to spawn/load"))
			]
			//+ SVerticalBox::Slot()
			//	.HAlign(HAlign_Center)
			//	.AutoHeight()
			//	[
			//		Locals::MakeButton(LOCTEXT("UpButtonLabel", "Browse"), FVector(0, 0, Factor))
			//	]
			+ SVerticalBox::Slot()
				[
					SAssignNew(ListViewWidget, SListView<TSharedPtr<FString>>)
					.ItemHeight(24)
					.ListItemsSource(&Items)
					.OnGenerateRow(this, &FConfigEditorPluginEdModeToolkit::OnGenerateRowForList)
				]
		];
		
	FModeToolkit::Init(InitToolkitHost);
}

FName FConfigEditorPluginEdModeToolkit::GetToolkitFName() const
{
	return FName("ConfigEditorPluginEdMode");
}

FText FConfigEditorPluginEdModeToolkit::GetBaseToolkitName() const
{
	return NSLOCTEXT("ConfigEditorPluginEdModeToolkit", "DisplayName", "ConfigEditorPluginEdMode Tool");
}

class FEdMode* FConfigEditorPluginEdModeToolkit::GetEditorMode() const
{
	return GLevelEditorModeTools().GetActiveMode(FConfigEditorPluginEdMode::EM_ConfigEditorPluginEdModeId);
}

TSharedRef<ITableRow> FConfigEditorPluginEdModeToolkit::OnGenerateRowForList(TSharedPtr<FString> Item, const TSharedRef<STableViewBase>& OwnerTable)
{
	// Create the row
	return
		SNew(STableRow< TSharedPtr<FString> >, OwnerTable)
		.Padding(2.0f)
		[
			SNew(STextBlock).Text(FText::FromString(*Item.Get()))
		];
}

#undef LOCTEXT_NAMESPACE
