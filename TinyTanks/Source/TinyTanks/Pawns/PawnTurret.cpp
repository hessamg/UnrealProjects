// Developed by Sam Ganjian 2020.

#include "PawnTurret.h"
#include "PawnTank.h"

#include "Kismet/GameplayStatics.h"

// Called when the game starts or when spawned
void APawnTurret::BeginPlay()
{
    Super::BeginPlay();

    GetWorld()->GetTimerManager().SetTimer(FireRateTimerHandle, this, &APawnTurret::CheckfireCondition, FireRate, true);

    PlayerPawn = Cast<APawnTank>(UGameplayStatics::GetPlayerPawn(this, 0));
}

// Called every frame
void APawnTurret::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void APawnTurret::CheckfireCondition()
{
    if (PlayerPawn)
    {
        if(RetrunDistanceToPlayer() <= FireRange)
        {
            //Fire
            UE_LOG(LogTemp, Warning, TEXT("Fire!"));
        }
    }
}

float APawnTurret::RetrunDistanceToPlayer() const
{
    if (!PlayerPawn)
    {
        return 0.f;
    }

    return FVector::Dist(PlayerPawn->GetActorLocation(), GetActorLocation());
}