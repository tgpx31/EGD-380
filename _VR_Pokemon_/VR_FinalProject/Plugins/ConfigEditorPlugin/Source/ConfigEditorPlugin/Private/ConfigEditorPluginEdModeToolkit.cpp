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
			// Grab the Asset
			/*IAssetTools& A_T = FModuleManager::Get().LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();
			A_T.ImportAssets("...");*/

			// enter a name corresponding to the data file
			// load data from the file into values in an instantiated Pokemon

			
			
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
				.Text(LOCTEXT("HelperLabel", "Press the button to select a config file to import"))
			]
			+ SVerticalBox::Slot()
				.HAlign(HAlign_Center)
				.AutoHeight()
				[
					Locals::MakeButton(LOCTEXT("UpButtonLabel", "Browse"), FVector(0, 0, Factor))
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

#undef LOCTEXT_NAMESPACE
