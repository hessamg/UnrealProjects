// Developed by Sam Ganjian 2020.

#pragma once

#include "CoreMinimal.h"
#include "PawnBase.h"
#include "PawnTank.generated.h"

class USpringArmComponent;
class UCameraComponent;

UCLASS()
class TINYTANKS_API APawnTank : public APawnBase
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APawnTank();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent *PlayerInputComponent) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Component", meta = (AllowPrivateAccess = "true"))
	USpringArmComponent *SpringArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Component", meta = (AllowPrivateAccess = "true"))
	UCameraComponent *Camera;

	FVector MoveDirection;
	FQuat RotationDirection;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement", meta = (AllowPrivateAccess = "true"))
	float MoveSpeed = 500.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement", meta = (AllowPrivateAccess = "true"))
	float RotateSpeed = 200.0f;

	void CalculateMoveInput(float Value);
	void CalculateRotateInput(float Value);

	void Move();
	void Rotate();

};
