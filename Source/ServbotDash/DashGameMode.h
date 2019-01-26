// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"

#include "Blueprint/UserWidget.h"

#include "DashGameMode.generated.h"

/**
 *
 */

UCLASS()
class SERVBOTDASH_API ADashGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:

	/* change the current widget */
	UFUNCTION(BlueprintCallable, Category = "ServbotDash")
		void ChangeWidget(TSubclassOf<UUserWidget> NewWidgetClass);

protected:

	/* Called when the game starts */
	virtual void BeginPlay() override;

	/* The widget class to use as our HUD */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ServbotDash")
		TSubclassOf<UUserWidget> RunningWidget;

	/* The current widget to draw */
	UUserWidget* CurrentWidget;

};