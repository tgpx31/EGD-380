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
	Items.Empty();
	ListViewWidget = SNew(SListView<TSharedPtr<FString>>);
}

void FConfigEditorPluginEdModeToolkit::Init(const TSharedPtr<IToolkitHost>& InitToolkitHost)
{
	Items.Add(MakeShareable(new FString("Slowbro")));
	Items.Add(MakeShareable(new FString("Charizard")));

	struct Locals
	{
		static bool IsWidgetEnabled()
		{
			return true;
		}

		static FReply OnButtonClick(TSharedPtr< SListView< TSharedPtr<FString> > > list)
		{
			FActorSpawnParameters SpawnParam;
			APokemon* newPokemon = GWorld->SpawnActor<APokemon>(APokemon::StaticClass(), FVector::ZeroVector, FRotator::ZeroRotator, SpawnParam);

			if (!list.IsValid())
				return FReply::Handled();

			FString dirPath = "../../../../../ConfigFiles/";
			TSharedPtr<FString> fileName;
			fileName = *list->GetSelectedItems().GetData();
			const FString name = *fileName;
			FString resultData = "";
			dirPath.Append(name);

			const TCHAR* file = *dirPath;

			FFileHelper::LoadFileToString(resultData, file);

			// WE DID IT

			return FReply::Handled();
		}

		static TSharedRef<SWidget> MakeButton(FText InLabel, TSharedPtr< SListView< TSharedPtr<FString> > > list)
		{
			return SNew(SButton)
				.Text(InLabel)
				.OnClicked_Static(&Locals::OnButtonClick, list);
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
			+ SVerticalBox::Slot()
				[
					SAssignNew(ListViewWidget, SListView<TSharedPtr<FString>>)
					.ItemHeight(24)
					.ListItemsSource(&Items)
					.OnGenerateRow(this, &FConfigEditorPluginEdModeToolkit::OnGenerateRowForList)
					.SelectionMode(ESelectionMode::Single)
				]
			+ SVerticalBox::Slot()
				.HAlign(HAlign_Center)
				.AutoHeight()
				[
					Locals::MakeButton(LOCTEXT("ButtonLabel", "Create Pokemon"), ListViewWidget)
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
