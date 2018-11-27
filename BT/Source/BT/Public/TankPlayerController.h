// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"

#include "TankPlayerController.generated.h"  //Must be last include

class ATank;
/**
 * 
 */
UCLASS()
class BT_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

		ATank* GetControlledTank() const;

		virtual void Tick(float DeltaTime) override;

		virtual void BeginPlay() override;

private:
		//Moves the barrel towards the crosshair
		void AimTowardsCrosshair();

		//Return an OUT parameter, true if hit landscape
		bool GetSightRayHitLocation(FVector& HitLocation) const;

		UPROPERTY(EditAnywhere)
		float CrossHairXLocation = 0.5;

		UPROPERTY(EditAnywhere)
		float CrossHairYLocation = 0.3333;

		bool GetLookDirection(FVector2D ScreenLocation, FVector & LookDirection) const;

		UPROPERTY(EditAnywhere)
		float LineTraceRange = 1000000;
		
		
		bool GetLookVectorHitLocation(FVector LookDirection, FVector & HitLocation) const;

	
};
