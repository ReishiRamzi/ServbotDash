// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/ArrowComponent.h"
#include "Components/BoxComponent.h"
//#include "Collectible.h"
#include "RuinTile.generated.h"

UCLASS()
class SERVBOTDASH_API ARuinTile : public AActor
{
	GENERATED_BODY()
	
public:	

	// Sets default values for this actor's properties
	ARuinTile();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/* 
	*	SCENE COMPONENTS 
	*/

	// Root scene component
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ServbotDash")
	USceneComponent* Root;

	// the blueprint component to represent attachment point
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ServbotDash")
		UArrowComponent* SpawnAttachArrow;

	// blueprint component for the end of tile volume trigger
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ServbotDash")
		UBoxComponent* TileEndTrigger;

	// blueprint component for the spawn volume
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "ServbotDash")
		UBoxComponent* SpawnArea;

	// Floor
	UPROPERTY(EditDefaultsonly, BlueprintReadWrite)
		USceneComponent* FloorMeshRoot;

	// Ceiling
	UPROPERTY(EditDefaultsonly, BlueprintReadWrite)
		USceneComponent* CeilingMeshRoot;
	// Wall
	UPROPERTY(EditDefaultsonly, BlueprintReadWrite)
		USceneComponent* WallMeshRoot;



	/* 
	*	TILE VARIABLES 
	*/

	// the maximum amount of collectibles to spawn
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ServbotDash")
		int32 MaxZenny;

	// the minimum amount of collectibles to spawn
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ServbotDash")
		int32 MinZenny;

	// the attachment point transform for the next tile
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ServbotDash")
		FTransform SpawnAttachPoint;

	// gets the FTransform of the attach point
	UFUNCTION(BlueprintPure, Category = "ServbotDash")
	FTransform GetAttachTransform();

	/* gets the FTransform of the attach point */
	UFUNCTION(BlueprintPure, Category = "ServbotDash")
		FVector GetRandomPointInArea();

	// Generate collectibles in the spawn area
	UFUNCTION(BlueprintCallable, Category = "ServbotDash")
	void GenerateCollectibles();

	// Spawn Zenny
	UFUNCTION(BlueprintCallable, Category = "ServbotDash")
		void SpawnRefractors();
	//class TArray <UCollectible*> Collectibles;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ServbotDash")
	//TArray <TSubclassOf<UCollectible>> CollectibleType;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;



	// declare overlap begin function
	//UFUNCTION(CallInEditor, Category = "ServbotDash")
	//void EndTriggerBeginOverlap
	//(
	//	UPrimitiveComponent* OverlappedComponent,
	//	AActor* OtherActor,
	//	UPrimitiveComponent* OtherComp,
	//	int32 OtherBodyIndex,
	//	bool bFromSweep,
	//	const FHitResult &SweepResult
	//);
private:


};
