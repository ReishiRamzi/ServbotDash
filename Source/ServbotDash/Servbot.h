// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Servbot.generated.h"

UCLASS()
class SERVBOTDASH_API AServbot : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AServbot();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/*
	Zenny
	*/

	/* Current Score */
	UPROPERTY(BlueprintReadOnly, Category = "ServbotDash")
		int32 Zenny;

	/* add the passed value of refractor to score */
	UFUNCTION(BlueprintCallable, Category = "ServbotDash")
		void AddZenny(int32 Value);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
