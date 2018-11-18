// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Engine/World.h"  //for GetWorld()



void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();  //calls the default first in the base class

	auto ControlledTank = GetControlledTank();

	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not possessing a tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController possessing %s"), *(ControlledTank->GetName()));  //* here turns the string we get to a tchar because of how this UE macro works
	}

	UE_LOG(LogTemp, Warning, TEXT("PlayerController Begin Play"));
}



void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}



ATank * ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());  //returns the pawn ATank is the type of pawn this must be set in theTank_BP as the parent class
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }

	FVector HitLocation; //Out parameter
	if (GetSightRayHitLocation(HitLocation))  //if true (it hits the terrain) log where it hits 
	{
		GetControlledTank()->AimAt(HitLocation);
	}

}

bool ATankPlayerController::GetSightRayHitLocation(FVector & HitLocation) const  //passing a reference of HitLocation above
{
	//Find the crosshair position
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);


	FVector2D ScreenLocation = FVector2D(ViewportSizeX*CrossHairXLocation, ViewportSizeY*CrossHairYLocation);
	//UE_LOG(LogTemp, Warning, TEXT("ScreenLocation: %s"), *ScreenLocation.ToString());

	//De-project the screen position of the crosshair to a world direction
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		//UE_LOG(LogTemp, Warning, TEXT("Look Direction: %s"), *LookDirection.ToString());
		GetLookVectorHitLocation(LookDirection, HitLocation);
	}
	
	//Line-trace along that look direction and see what we hit (up to a max range)
	return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector & LookDirection) const
{
	//FVector WorldDirection;
	FVector CameraWorldLocation;  //Must be passed in - won't use
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, LookDirection);
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector & HitLocation) const
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LineTraceRange * LookDirection);

	if (GetWorld()->LineTraceSingleByChannel(
		HitResult,
		StartLocation,
		EndLocation,
		ECollisionChannel::ECC_Visibility)
		)
	
	
	{
		HitLocation = HitResult.Location;
		return true;
	}

	HitLocation = FVector(0);

	return false;
}
