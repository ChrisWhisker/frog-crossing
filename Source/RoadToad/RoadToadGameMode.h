// Copyright © 2023-2024 Chris Worcester. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "RoadToad/RoadToadDataTypes.h"
#include "RoadToadGameMode.generated.h"

/**
 * Base game mode for Road Toad
 */
UCLASS()
class ROADTOAD_API ARoadToadGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly)
	bool ToadCanJump = true;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void KillToad(ECauseOfDeath CauseOfDeath);
};
