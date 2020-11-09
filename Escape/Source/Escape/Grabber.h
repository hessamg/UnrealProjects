// Developed by Sam Ganjian 2020.

#pragma once

#include <tuple>

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Grabber.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UGrabber();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

private:
	void FindPhysicsHandle();
	void SetupInputComponent();

	// Return the first actor within reach with physics body.
	FHitResult GetFisrtPhysicsObjectInReach() const;

	//Return the Line Trace end.
	FVector GetPlayersReach() const;

	// Get Players Position in world.
	std::tuple<FVector, FRotator> GetPlayersWorldPosition() const;

	void Grab();
	void Release();

private:
	float Reach = 220.f;

	UPROPERTY()
	UPhysicsHandleComponent *PhysicsHandle = nullptr;
	
	UPROPERTY()
	UInputComponent *InputComponent = nullptr;
};
