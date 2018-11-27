// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"


#include "Tank.generated.h"

class UTankBarrel;  //Forward declaration allows to reference this class type here
class UTankAimingComponent;

UCLASS()
class BT_API ATank : public APawn
{
	GENERATED_BODY()

public:
	


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UTankAimingComponent* TankAimingComponent = nullptr;

public:	

	// Sets default values for this pawn's properties
	ATank();

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetBarrelReference(UTankBarrel * BarrelToSet);  //We are setting the barrel at start for all tanks in blueprint


	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void AimAt(FVector HitLocation);
private:

	UPROPERTY(EditAnywhere, Category = Firing)
	float LaunchSpeed = 100000;  //1000 m/s

	
};
