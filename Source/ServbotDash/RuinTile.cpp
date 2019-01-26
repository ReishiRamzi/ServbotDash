// Fill out your copyright notice in the Description page of Project Settings.
#include "RuinTile.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
ARuinTile::ARuinTile()
{
 	// Don't need tick
	PrimaryActorTick.bCanEverTick = false;

	// Create the scene root
	Root = CreateDefaultSubobject<USceneComponent>("Root");
	RootComponent = Root;

	// add the attach arrow component to the hierarchy
	SpawnAttachArrow = CreateDefaultSubobject<UArrowComponent>("Arrow");
	SpawnAttachArrow->SetupAttachment(Root);

	// set transform of this attach point
	SpawnAttachPoint = SpawnAttachArrow->GetComponentTransform();

	// add the spawn volume box component to the hierarchy
	SpawnArea = CreateDefaultSubobject<UBoxComponent>("SpawnArea");
	SpawnArea->SetupAttachment(Root);

	// add the floor mesh root scene component to the hierarchy
	FloorMeshRoot = CreateDefaultSubobject<USceneComponent>("FloorMeshRoot");
	FloorMeshRoot->SetupAttachment(Root);

	// add the floor mesh root scene component to the hierarchy
	CeilingMeshRoot = CreateDefaultSubobject<USceneComponent>("CeilingMeshRoot");
	CeilingMeshRoot->SetupAttachment(Root);

	// add the wall mesh root scene component to the hierarchy
	WallMeshRoot = CreateDefaultSubobject<USceneComponent>("WallMeshRoot");
	WallMeshRoot->SetupAttachment(Root);

	// Add the end trigger to the hierarchy
	TileEndTrigger = CreateDefaultSubobject<UBoxComponent>("TileEndTrigger");
	TileEndTrigger->SetupAttachment(Root);

	//TileEndTrigger->OnComponentBeginOverlap.AddDynamic(this, &ARuinTile::EndTriggerBeginOverlap);

}

// Called when the game starts or when spawned
void ARuinTile::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ARuinTile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// returns FTransform of the attach point
FTransform ARuinTile::GetAttachTransform()
{
	SpawnAttachPoint = SpawnAttachArrow->GetComponentTransform();
	return 	SpawnAttachPoint;
}


void ARuinTile::GenerateCollectibles()
{
	//SpawnArea.getbox
	SpawnRefractors();

}

FVector ARuinTile::GetRandomPointInArea()
{
	FVector AreaOrigin = SpawnArea->Bounds.Origin;
	FVector AreaExtent = SpawnArea->Bounds.BoxExtent;
	
	return UKismetMathLibrary::RandomPointInBoundingBox(AreaOrigin, AreaExtent);
}

void ARuinTile::SpawnRefractors()
{
	UWorld* const World = GetWorld();
	if (World)
	{
		int32 rand = UKismetMathLibrary::RandomIntegerInRange(MinZenny, MaxZenny);

		for (int i = 0; i < rand; i++)
		{

			//TSubclassOf<UCollectible> CollectibleType;
			FTransform SpawnTransform;
			FVector SpawnLocation = GetRandomPointInArea();
			SpawnTransform.SetLocation(SpawnLocation);
			UE_LOG(LogTemp, Warning, TEXT("spawning zenny"));
			//UCollectible* ReturnCollectible = World->SpawnActor<UCollectible>(CollectibleType, SpawnTransform);
			//Collectibles.Add(ReturnCollectible);
			//// Collectibles[i] = ReturnCollectible;
		}
	}
}
//void ARuinTile::EndTriggerBeginOverlap
//	(
//	UPrimitiveComponent* OverlappedComponent,
//	AActor* OtherActor,
//	UPrimitiveComponent* OtherComp,
//	int32 OtherBodyIndex,
//	bool bFromSweep,
//	const FHitResult &SweepResult
//	)
//{
//	//AActor* ServBot = <AServbot>OtherActor;
//	UE_LOG(LogTemp, Warning, TEXT("passed the end trigger"));
//
//}


