// This class is specific to AI controlled tanks

#include "TankAIController.h"
#include "Engine/World.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();  //calls the default first in the base class

	auto PlayerTank = GetPlayerTank();

	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController can't find player tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController found player: %s"), *(PlayerTank->GetName()));  //* here turns the string we get to a tchar because of how this UE macro works
	}

	UE_LOG(LogTemp, Warning, TEXT("AIController Begin Play"));
}

void ATankAIController::Tick(float DeltaTime)
{

	Super::Tick(DeltaTime);
	if (GetPlayerTank())
	{
		//Move Towards player
		
		FVector HitLocation; //Out parameter
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
	}



}

ATank * ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());  //returns the pawn ATank is the type of pawn this must be set in the Tank_BP as the parent class
}

ATank * ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();

	if (!PlayerPawn) { return nullptr; }
	{
		return Cast<ATank>(PlayerPawn);
	}
}
