// Copyright Epic Games, Inc. All Rights Reserved.


#include "RobotHackAndSlashPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"
#include "InputMappingContext.h"
#include "RobotHackAndSlashCameraManager.h"

ARobotHackAndSlashPlayerController::ARobotHackAndSlashPlayerController()
{
	// set the player camera manager class
	PlayerCameraManagerClass = ARobotHackAndSlashCameraManager::StaticClass();
}

void ARobotHackAndSlashPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// Add Input Mapping Context
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		for (UInputMappingContext* CurrentContext : DefaultMappingContexts)
		{
			Subsystem->AddMappingContext(CurrentContext, 0);
		}
	}
}
