// Developed by Sam Ganjian 2020.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/AudioComponent.h"
#include "Engine/TriggerVolume.h"
#include "OpenDoor.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UOpenDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTimSe, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

private:
	void GetPressurePlate();
	void OpenDoor(const float &DeltaTime);
	void CloseDoor(const float &DeltaTime);
	float TotalMassofActors() const;
	void GetAudioComponent();

private:
	float InitialYaw;
	float CurrentYaw;

	bool PlayedOpenDoorSound = false;

	UPROPERTY(EditAnywhere)
	float MassToOpenDoor = 50.f;
	
	UPROPERTY(EditAnywhere)
	float OpenAngle = 90.f;

	float DoorLastOpenedTimeInSeconds = 0.f;

	UPROPERTY(EditAnywhere)
	float DoorCloseDelay = 0.8f;

	UPROPERTY(EditAnywhere)
	float DoorOpenSpeed = 1.f;

	UPROPERTY(EditAnywhere)
	float DoorCloseSpeed = 2.f;

	UPROPERTY(EditAnywhere)
	ATriggerVolume *PressurePlate = nullptr;

	UPROPERTY()
	UAudioComponent *AudioComponent = nullptr;
};
