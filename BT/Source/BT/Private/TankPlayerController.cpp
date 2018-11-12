// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"



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

ATank * ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());  //returns the pawn ATank is the type of pawn this must be set in theTank_BP as the parent class
}