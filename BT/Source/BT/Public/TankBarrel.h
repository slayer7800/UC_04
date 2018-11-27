// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))  //can hide categoreis by doing ,hidecategories = ("Collision") for example
class BT_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	//-1 is max downward movement +1 is max upward movement
	void Elevate(float RelativeSpeed);

private:

	UPROPERTY(EditAnywhere)
	float MaxDegreesPerSecond = 5;
	
	UPROPERTY(EditAnywhere)
	float MaxElevationDegrees = 40; 
	
	UPROPERTY(EditAnywhere)
	float MinElevationDegrees = 0; 
};
