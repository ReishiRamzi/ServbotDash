// Fill out your copyright notice in the Description page of Project Settings.

#include "Servbot.h"

// Sets default values
AServbot::AServbot()
{

}

// Called when the game starts or when spawned
void AServbot::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AServbot::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AServbot::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

/* Adds passed zenny value to total zenny */
void AServbot::AddZenny(int32 Value)
{
	Zenny += Value;
}

