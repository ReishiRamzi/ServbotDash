// Fill out your copyright notice in the Description page of Project Settings.

#include "DashGameMode.h"

#include "Kismet/KismetMathLibrary.h"

void ADashGameMode::BeginPlay()
{
	Super::BeginPlay();

	// Initialize the environment
	ChangeWidget(RunningWidget);

}

/* Changes the screen overlay to the specified Widget */

void ADashGameMode::ChangeWidget(TSubclassOf<UUserWidget> NewWidgetClass)
{
	if (CurrentWidget != nullptr)
	{
		CurrentWidget->RemoveFromViewport();
		CurrentWidget = nullptr;
	}
	if (NewWidgetClass != nullptr)
	{
		CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), NewWidgetClass);
		if (CurrentWidget != nullptr)
		{
			CurrentWidget->AddToViewport();
		}
	}
}

