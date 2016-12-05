// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "ConfigImport2PrivatePCH.h"

#include "SlateBasics.h"
#include "SlateExtras.h"

#include "ConfigImport2Style.h"
#include "ConfigImport2Commands.h"

#include "LevelEditor.h"

static const FName ConfigImport2TabName("ConfigImport2");

#define LOCTEXT_NAMESPACE "FConfigImport2Module"

void FConfigImport2Module::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	
	FConfigImport2Style::Initialize();
	FConfigImport2Style::ReloadTextures();

	FConfigImport2Commands::Register();
	
	PluginCommands = MakeShareable(new FUICommandList);

	PluginCommands->MapAction(
		FConfigImport2Commands::Get().PluginAction,
		FExecuteAction::CreateRaw(this, &FConfigImport2Module::PluginButtonClicked),
		FCanExecuteAction());
		
	FLevelEditorModule& LevelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");
	
	{
		TSharedPtr<FExtender> MenuExtender = MakeShareable(new FExtender());
		MenuExtender->AddMenuExtension("WindowLayout", EExtensionHook::After, PluginCommands, FMenuExtensionDelegate::CreateRaw(this, &FConfigImport2Module::AddMenuExtension));

		LevelEditorModule.GetMenuExtensibilityManager()->AddExtender(MenuExtender);
	}
	
	{
		TSharedPtr<FExtender> ToolbarExtender = MakeShareable(new FExtender);
		ToolbarExtender->AddToolBarExtension("Settings", EExtensionHook::After, PluginCommands, FToolBarExtensionDelegate::CreateRaw(this, &FConfigImport2Module::AddToolbarExtension));
		
		LevelEditorModule.GetToolBarExtensibilityManager()->AddExtender(ToolbarExtender);
	}

	UE_LOG(LogTemp, Warning, TEXT("ConfigImporter2 Starting up"));
}

void FConfigImport2Module::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	UE_LOG(LogTemp, Warning, TEXT("ConfigImporter2 Shutting down"));
	FConfigImport2Style::Shutdown();

	FConfigImport2Commands::Unregister();
}

void FConfigImport2Module::PluginButtonClicked()
{
	// Put your "OnButtonClicked" stuff here
	FText DialogText = FText::Format(
							LOCTEXT("PluginButtonDialogText", "Add code to {0} in {1} to override this button's actions. Fuck you Brian."),
							FText::FromString(TEXT("FConfigImport2Module::PluginButtonClicked()")),
							FText::FromString(TEXT("ConfigImport2.cpp"))
					   );
	FMessageDialog::Open(EAppMsgType::Ok, DialogText);
}

void FConfigImport2Module::AddMenuExtension(FMenuBuilder& Builder)
{
	Builder.AddMenuEntry(FConfigImport2Commands::Get().PluginAction);
}

void FConfigImport2Module::AddToolbarExtension(FToolBarBuilder& Builder)
{
	Builder.AddToolBarButton(FConfigImport2Commands::Get().PluginAction);
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FConfigImport2Module, ConfigImport2)