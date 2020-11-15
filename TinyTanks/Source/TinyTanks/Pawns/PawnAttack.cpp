// Developed by Sam Ganjian 2020.

#include "PawnAttack.h"

#include "Camera/CameraComponent.h"
#include "GameFrameWork/SpringArmComponent.h"

APawnAttack::APawnAttack()
{
    SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
    SpringArm->SetupAttachment(RootComponent);

    Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
    Camera->SetupAttachment(SpringArm);
}

// Called when the game starts or when spawned
void APawnAttack::BeginPlay()
{
    Super::BeginPlay();
}

// Called every frame
void APawnAttack::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void APawnAttack::SetupPlayerInputComponent(UInputComponent *PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);
}