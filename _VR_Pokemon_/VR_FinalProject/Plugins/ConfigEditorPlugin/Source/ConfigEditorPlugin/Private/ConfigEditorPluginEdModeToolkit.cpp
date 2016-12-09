// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "ConfigEditorPluginPrivatePCH.h"
#include "ConfigEditorPluginEdMode.h"
#include "ConfigEditorPluginEdModeToolkit.h"
#include "Developer/AssetTools/Public/AssetToolsModule.h"

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
			IAssetTools& A_T = FModuleManager::Get().LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();
			A_T.ImportAssets("...");
			//TArray<UObject*> ReturnObjects;
			//FString FileTypes, AllExtensions;
			//TArray<UFactory*> Factories;

			//// Get the list of valid factories
			//for (TObjectIterator<UClass> It; It; ++It)
			//{
			//	UClass* CurrentClass = (*It);

			//	if (CurrentClass->IsChildOf(UFactory::StaticClass()) && !(CurrentClass->HasAnyClassFlags(CLASS_Abstract)))
			//	{
			//		UFactory* Factory = Cast<UFactory>(CurrentClass->GetDefaultObject());
			//		if (Factory->bEditorImport)
			//		{
			//			Factories.Add(Factory);
			//		}
			//	}
			//}

			//USelection* SelectedActors = GEditor->GetSelectedActors();

			//// Let editor know that we're about to do something that we want to undo/redo
			//GEditor->BeginTransaction(LOCTEXT("MoveActorsTransactionName", "MoveActors"));

			//// For each selected actor
			//for (FSelectionIterator Iter(*SelectedActors); Iter; ++Iter)
			//{
			//	if (AActor* LevelActor = Cast<AActor>(*Iter))
			//	{
			//		// Register actor in opened transaction (undo/redo)
			//		LevelActor->Modify();
			//		// Move actor to given location
			//		LevelActor->TeleportTo(LevelActor->GetActorLocation() + InOffset, FRotator(0, 0, 0));
			//	}
			//}

			//// We're done moving actors so close transaction
			//GEditor->EndTransaction();

			//return FReply::Handled();
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
