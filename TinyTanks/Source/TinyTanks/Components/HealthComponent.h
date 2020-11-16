// Developed by Sam Ganjian 2020.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"

class ATankGameModeBase;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TINYTANKS_API UHealthComponent : public UActorComponent
{
GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	UHealthComponent();

	UFUNCTION()
	void TakeDamage(AActor *DamagedActor, float Damage, const UDamageType *DamageType, AController *InstigatedBy, AActor *DamageCauser);


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere)
	float DefaultHealth = 100.f;
	float Health = 0.f;

	ATankGameModeBase *GameModeRef;
};
