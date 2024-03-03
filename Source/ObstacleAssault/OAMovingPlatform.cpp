// Fill out your copyright notice in the Description page of Project Settings.


#include "OAMovingPlatform.h"

// Sets default values
AOAMovingPlatform::AOAMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AOAMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();
	
}

// Called every frame
void AOAMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MovePlatform(DeltaTime);
	RotatePlatform(DeltaTime);

}

void AOAMovingPlatform::MovePlatform(float DeltaTime)
{
	FVector Location = GetActorLocation();
	Location = Location + MovementDir.GetSafeNormal() * (Velocity * DeltaTime);
	float DistanceTraveled = FVector::Dist(StartLocation, Location);

	if (DistanceTraveled > MoveDistance)
	{
		StartLocation = StartLocation + (MoveDistance * MovementDir.GetSafeNormal() * (Velocity < 0 ? -1.f : 1.f));
		SetActorLocation(StartLocation);
		Velocity = -Velocity;
	}
	else
	{
		SetActorLocation(Location);
	}
}

void AOAMovingPlatform::RotatePlatform(float DeltaTime)
{
	AddActorLocalRotation(RotationRate * DeltaTime);
}

