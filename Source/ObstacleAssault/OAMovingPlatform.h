// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "OAMovingPlatform.generated.h"

UCLASS()
class OBSTACLEASSAULT_API AOAMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AOAMovingPlatform();

protected:

	UPROPERTY(EditAnywhere, Category = "Platform")
	float Velocity = 1.f;

	UPROPERTY(EditAnywhere, Category = "Platform")
	FVector MovementDir = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, Category = "Platform")
	float MoveDistance = 100.f;

	UPROPERTY(EditAnywhere, Category = "Platform")
	FRotator RotationRate = FRotator::ZeroRotator;

	FVector StartLocation = FVector::ZeroVector;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void MovePlatform(float DeltaTime);

	void RotatePlatform(float DeltaTime);


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


};
