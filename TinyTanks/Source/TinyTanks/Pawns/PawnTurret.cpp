// Developed by Sam Ganjian 2020.

#include "PawnTurret.h"

#include"Kismet/GameplayStatics.h"

APawnTurret::APawnTurret()
{
    GetWorld()->GetTimerManager().SetTimer(FireRateTimerHandle, this, &APawnTurret::CheckfireCondition, FireRate, true);
}

// Called when the game starts or when spawned
void APawnTurret::BeginPlay()
{
    Super::BeginPlay();
}

// Called every frame
void APawnTurret::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

// // Called to bind functionality to input
// void APawnTurret::SetupPlayerInputComponent(UInputComponent *PlayerInputComponent)
// {
//     Super::SetupPlayerInputComponent(PlayerInputComponent);
// }

void APawnTurret::CheckfireCondition() 
{
    UE_LOG(LogTemp, Warning, TEXT("Fire Condition"));
}