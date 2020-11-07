// Developed by Sam Ganjian 2020.
#include "OpenDoor.h"

#include "Components/PrimitiveComponent.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"

// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();

	InitialYaw = GetOwner()->GetActorRotation().Yaw;
	CurrentYaw = InitialYaw;
	OpenAngle += InitialYaw;

	GetPressurePlate();
	GetAudioComponent();
}

// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (TotalMassofActors() > MassToOpenDoor)
	{
		OpenDoor(DeltaTime);
		DoorLastOpenedTimeInSeconds = GetWorld()->GetTimeSeconds();
	}
	else
	{
		if (GetWorld()->GetTimeSeconds() - DoorLastOpenedTimeInSeconds > DoorCloseDelay)
		{
			CloseDoor(DeltaTime);
		}
	}
}

void UOpenDoor::GetPressurePlate()
{
	if (!PressurePlate)
	{
		UE_LOG(LogTemp, Error, TEXT("%s has the open door component on it, but has no PressurePlate set."), *GetOwner()->GetName())
	}
}

void UOpenDoor::GetAudioComponent()
{
	AudioComponent = GetOwner()->FindComponentByClass<UAudioComponent>();

	if (AudioComponent == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("%s is missing audio component."), *GetOwner()->GetName());
	}
}

void UOpenDoor::OpenDoor(const float &DeltaTime)
{
	CurrentYaw = FMath::FInterpTo(CurrentYaw, OpenAngle, DeltaTime, DoorOpenSpeed);

	FRotator DoorRotation = GetOwner()->GetActorRotation();

	DoorRotation.Yaw = CurrentYaw;
	GetOwner()->SetActorRotation(DoorRotation);

	if (AudioComponent && !PlayedOpenDoorSound)
	{
		AudioComponent->Play();
		PlayedOpenDoorSound = true;
	}
}

void UOpenDoor::CloseDoor(const float &DeltaTime)
{
	CurrentYaw = FMath::FInterpTo(CurrentYaw, InitialYaw, DeltaTime, DoorCloseSpeed);

	FRotator DoorRotation = GetOwner()->GetActorRotation();

	DoorRotation.Yaw = CurrentYaw;
	GetOwner()->SetActorRotation(DoorRotation);

	if (AudioComponent && PlayedOpenDoorSound)
	{
		AudioComponent->Play();
		PlayedOpenDoorSound = false;
	}
}

float UOpenDoor::TotalMassofActors() const
{
	float TotalMass = 0.f;

	TArray<AActor *> OverlappingActors;
	if (PressurePlate)
	{
		PressurePlate->GetOverlappingActors(OUT OverlappingActors);
	}

	for (auto *Actor : OverlappingActors)
	{
		TotalMass += Actor->FindComponentByClass<UPrimitiveComponent>()->GetMass();
	}

	return TotalMass;
}