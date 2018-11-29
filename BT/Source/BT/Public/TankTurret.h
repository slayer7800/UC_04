// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BT_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	

private:

	UPROPERTY(EditAnywhere)
	float MaxDegreesPerSecond = 20;

public:
	void Rotate(float RelativeSpeed);
	
};
