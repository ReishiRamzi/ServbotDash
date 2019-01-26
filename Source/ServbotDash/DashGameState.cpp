// Fill out your copyright notice in the Description page of Project Settings.

#include "DashGameState.h"


void ADashGameState::BeginPlay()
{
	Super::BeginPlay();

	// Initialize the environment
	InitializeCourse();

}

void ADashGameState::InitializeCourse()
{
	// Initialize the tiles

	if (NumberOfTiles < MaxTiles)
	{

		for (int32 i = 0; i < MaxTiles - 4; i++)
		{
			AddRuinTile(SpawnTransform);
		}
	}
}

/* Adds a course tile at the specified transform */
void ADashGameState::AddRuinTile(FTransform NextSpawnTransform)
{

	// initialize random tile variables
	int32 RandIntStraights = FMath::RandRange(MinStraights, MaxStraights);	

	// if we are above the max amount of straight tiles, 
	// dequeue the oldest tile and destroy it 
	if (NumberOfTiles > MaxTiles)
	{
		DestroyTile();
	}

	// if we're under the random limit for straight tiles, spawn straight tile
	if (CurrentStraights < RandIntStraights)
	{
		AddStraightTile();
	}	
	// if we're at the straight tile limit, spawn corner tile
	else
	{
		AddCornerTile();
	}
}

void ADashGameState::DestroyTile()
{
	ARuinTile* TileToDequeue;
	RuinTileQueue.Dequeue(TileToDequeue);
	TileToDequeue->Destroy();
	NumberOfTiles--;
}

void ADashGameState::AddStraightTile()
{
	// get a reference to the world
	UWorld* world = GetWorld();

	// generate random number for straights (0 - 2)
	int32 RandIntStraightType = FMath::RandRange(0, 3);

	TSubclassOf<ARuinTile> TileType;
	// get the random straight tile
	TileType = RuinTiles[RandIntStraightType];

	// add a straight floor tile
	ARuinTile* ReturnTile = world->SpawnActor<ARuinTile>(TileType, SpawnTransform);

	// increment current straights
	CurrentStraights++;

	// increment number of tiles
	NumberOfTiles++;

	//set the spawn transform for the next tile
	SpawnTransform = ReturnTile->GetAttachTransform();

	// Enqueue the tile
	RuinTileQueue.Enqueue(ReturnTile);
}

void ADashGameState::AddCornerTile()
{
	UWorld* world = GetWorld();
	// random corner tile 
	int32 RandIntCorner = FMath::RandRange(4, 5);

	// get the random corner tile
	TSubclassOf<ARuinTile> TileToSpawn = RuinTiles[RandIntCorner];

	// add a corner floor tile
	ARuinTile* ReturnTile = world->SpawnActor<ARuinTile>(TileToSpawn, SpawnTransform);

	// reset straights to 0
	CurrentStraights = 0;

	// increment number of tiles
	NumberOfTiles++;

	//set the spawn transform for the next tile
	SpawnTransform = ReturnTile->GetAttachTransform();

	// Enqueue the tile
	RuinTileQueue.Enqueue(ReturnTile);

}