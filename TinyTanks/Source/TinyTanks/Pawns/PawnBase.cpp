// Developed by Sam Ganjian 2020.

#include "PawnBase.h"

#include "Components/CapsuleComponent.h"

// Sets default values
APawnBase::APawnBase()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Collider"));
	RootComponent = CapsuleComponent;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));
	BaseMesh->SetupAttachment(RootComponent);

	TurretMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Turret Mesh"));
	TurretMesh->SetupAttachment(BaseMesh);

	ProjectileSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Projectile Spawn Point"));
	ProjectileSpawnPoint->SetupAttachment(TurretMesh);
}

void APawnBase::RotateTurret(FVector LookAtTarget)
{
	const auto LookAtTargetCleaned = FVector(LookAtTarget.X, LookAtTarget.Y, TurretMesh->GetComponentLocation().Z);
	const auto StartLocation = TurretMesh->GetComponentLocation();
	const FRotator TurratRotation = FVector( LookAtTargetCleaned - StartLocation).Rotation();

	TurretMesh->SetWorldRotation(TurratRotation);
}

void APawnBase::Fire()
{
	UE_LOG(LogTemp, Warning, TEXT("Fire!"));
}

void APawnBase::HandleDestruction()
{
}
