// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"

#include "Queue.h"
#include "RuinTile.h"

#include "DashGameState.generated.h"

/**
 * 
 */
UCLASS()
class SERVBOTDASH_API ADashGameState : public AGameStateBase
{
	GENERATED_BODY()

public:

	/* the next attach point for spawning tiles */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ServbotDash")
		FTransform SpawnTransform;

	/* Adds the next tile */
	UFUNCTION(BlueprintCallable, Category = "ServbotDash")
		void AddRuinTile(FTransform NextSpawnTransform);

	/* Adds the next tile */
	UFUNCTION(BlueprintCallable, Category = "ServbotDash")
		void InitializeCourse();

protected:

	/* Called when the game starts */
	virtual void BeginPlay() override;

	/*
		Course Variables
	*/

	/* Array of Ruin Tile Types */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ServbotDash")
		TArray< TSubclassOf<ARuinTile> > RuinTiles;

	/* a Queue of references to tiles in course */
	class TQueue<ARuinTile*> RuinTileQueue;

	/* Current amount of straight tiles */
	int32 CurrentStraights;

	/* Current number of tiles in the course */
	int32 NumberOfTiles;

	/* Maximum amount of tiles allowed on the course */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ServbotDash")
		int32 MaxTiles;

	/* Maximum amount of straight tiles*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ServbotDash")
		int32 MaxStraights;

	/* Minimum amount of straight tiles*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ServbotDash")
		int32 MinStraights;

	void DestroyTile();

	void AddStraightTile();

	void AddCornerTile();
	
};
