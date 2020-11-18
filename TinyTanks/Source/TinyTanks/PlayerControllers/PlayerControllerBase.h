// Developed by Sam Ganjian 2020.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PlayerControllerBase.generated.h"

/**
 * 
 */
UCLASS()
class TINYTANKS_API APlayerControllerBase : public APlayerController
{
	GENERATED_BODY()

public:
	void SetPlayerEnabledState(bool SetPlayerEnabled);
};
