// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "ConfigEditorPluginPrivatePCH.h"
#include "ConfigEditorPluginEdMode.h"
#include "ConfigEditorPluginEdModeToolkit.h"
#include "Developer/AssetTools/Public/AssetToolsModule.h"
#include "VRFirstPerson/Pokemon.h"
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
	Items.Add(MakeShareable(new FString("Snorlax")));
	Items.Add(MakeShareable(new FString("Raichu")));
	

	struct Locals
	{
		static bool IsWidgetEnabled()
		{
			return true;
		}

		static FReply OnButtonClick(FString item)
		{
			FActorSpawnParameters SpawnParam;
			APokemon* newPokemon = GWorld->SpawnActor<APokemon>(APokemon::StaticClass(), FVector::ZeroVector, FRotator::ZeroRotator, SpawnParam);

			FString result;

			// get the project path
			// append the file path
			FString filepath = FPaths::GetPath(FPaths::GetProjectFilePath());
			const TCHAR* name = *item;
			int count = item.GetAllocatedSize() / sizeof(TCHAR);
			filepath.AppendChars(TEXT("/ConfigFiles/"), 13);
			filepath.AppendChars(name, count-1);
			filepath.AppendChars(TEXT("_.acfg"), 6);
			
			if (FFileHelper::LoadFileToString(result, *filepath))
			{
				// Load data into instance

				TArray<FString> lines;
				const TCHAR* delim = TEXT("\n");

				result.ParseIntoArray(lines, delim, true);

				// Set the name
				newPokemon->SetActorLabel(lines[0]);
				newPokemon->mName = FText::FromString(*lines[0]);
				// load stats
				newPokemon->mMaxHealth = FCString::Atoi(*lines[1]);
				newPokemon->mCurrentHealth = FCString::Atoi(*lines[2]);
				newPokemon->mAttack = FCString::Atoi(*lines[3]);
				newPokemon->mDefense = FCString::Atoi(*lines[4]);
				newPokemon->mSpAttack = FCString::Atoi(*lines[5]);
				newPokemon->mSpDefense = FCString::Atoi(*lines[6]);
				newPokemon->mSpeed = FCString::Atoi(*lines[7]);

				// Load moves
				
				/*
				*	In the current implementation of the Pokemon and Move classes, it is impossible to load Moves via C++
				*	They must be loaded in the editor. This has been tested by myself and Gabe.
				*
				*
				*	Also, the Static Mesh also can't be loaded
				*	because it is a component of on the Pokemon class.
				*
				*	Myself and the rest of the team have slaved over source code and other sources for hours. Nothing yet.
				*/

				// load the mesh
				// thanks to Duncan Carroll for the tips on importing Static Meshes, but this shit is broken as fuck
				/*filepath = FPaths::GetPath(FPaths::GetProjectFilePath());
				int count = lines[12].GetAllocatedSize() / sizeof(TCHAR);
				filepath.AppendChars(*lines[12], count - 1);
				newPokemon->initMesh(filepath);*/

				// set mesh transform
				// Can't do this since we can't get the mesh to properly instantiate...

				// Load types
				newPokemon->setTypes(FCString::Atoi(*lines[13]), FCString::Atoi(*lines[14]));

				// Congrats, you did it...?
			}
			

			return FReply::Handled();
		}

		static TSharedRef<SWidget> MakeButton(FText InLabel, FString item)
		{
			return SNew(SButton)
				.Text(InLabel)
				.OnClicked_Static(&Locals::OnButtonClick, item);
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
			.Padding(32)
			[
				SNew(STextBlock)
				.AutoWrapText(true)
				.Text(LOCTEXT("HelperLabel", "Pick a Pokemon to instance:"))
			]
			/*+ SVerticalBox::Slot()
			.AutoHeight()
			.HAlign(HAlign_Center)
			.Padding(32)
			[
				SAssignNew(ListViewWidget, SListView<TSharedPtr<FString>>)
				.ItemHeight(24)
				.ListItemsSource(&Items)
				.OnGenerateRow(this, &FConfigEditorPluginEdModeToolkit::OnGenerateRowForList)
				.SelectionMode(ESelectionMode::Single)
			]*/
			+ SVerticalBox::Slot()
				.HAlign(HAlign_Left)
				.AutoHeight()
				[
					Locals::MakeButton(LOCTEXT("ButtonLabel_SB", "Create Slowbro"), FString("Slowbro"))
				]
			+ SVerticalBox::Slot()
				.HAlign(HAlign_Left)
				.AutoHeight()
				[
					Locals::MakeButton(LOCTEXT("ButtonLabel_CH", "Create Charizard"), FString("Charizard"))
				]
			/*+ SVerticalBox::Slot()
				.HAlign(HAlign_Left)
				.AutoHeight()
				[
					Locals::MakeButton(LOCTEXT("ButtonLabel_SN", "Create Snorlax"), FString("Snorlax"))
				]
			+ SVerticalBox::Slot()
				.HAlign(HAlign_Left)
				.AutoHeight()
				[
					Locals::MakeButton(LOCTEXT("ButtonLabel_RC", "Create Raichu"), FString("Raichu"))
				]*/
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
			SNew(STextBlock).Text(FText::FromString(*Item))
		];
}



#undef LOCTEXT_NAMESPACE
