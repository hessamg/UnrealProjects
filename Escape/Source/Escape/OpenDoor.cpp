// Developed by Sam Ganjian 2020.

#include "OpenDoor.h"
#include "GameFramework/Actor.h"

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
}

// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	UE_LOG(LogTemp, Warning, TEXT("%s"), *GetOwner()->GetActorRotation().ToString());
	UE_LOG(LogTemp, Warning, TEXT("%f"), TargetYaw);

	FRotator ClosedDoorRotation = GetOwner()->GetActorRotation();
	FRotator OpenedDoorRotation = ClosedDoorRotation;

	OpenedDoorRotation.Yaw = FMath::Lerp(OpenedDoorRotation.Yaw, TargetYaw,0.02f);

	GetOwner()->SetActorRotation(OpenedDoorRotation);

}