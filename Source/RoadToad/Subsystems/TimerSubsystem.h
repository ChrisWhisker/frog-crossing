// Copyright © 2023-2024 Chris Worcester. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "TimerSubsystem.generated.h"

class ARoadToadGameMode;
class URoadToadHUD;

/**
 * 
 */
UCLASS()
class ROADTOAD_API UTimerSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void RestartLifeTimer();

	UFUNCTION(BlueprintCallable)
	float GetLifeTimerSecondsLeft() const { return LifeTimerSecondsLeft; }

	UFUNCTION(BlueprintCallable)
	void PauseLifeTimer();

	UFUNCTION(BlueprintCallable)
	void TickLifeTimer(float SecondsPassed);

	UFUNCTION(BlueprintCallable)
	void RestartJumpTimer();

	UFUNCTION(BlueprintCallable)
	void TickJumpTimer(float SecondsPassed);

private:
	UPROPERTY()
	TObjectPtr<ARoadToadGameMode> RoadToadGameMode;

	UPROPERTY()
	TObjectPtr<URoadToadHUD> RoadToadHUD;

	// ***** Life timer properties *****
	// The life timer counts down to 0.

	UPROPERTY()
	FTimerHandle LifeTimerHandle;

	UPROPERTY()
	float LifeTimerMaxSeconds = 40;

	// Number of seconds left on the life timer. A life is lost when it reaches 0.
	UPROPERTY()
	float LifeTimerSecondsLeft;

	UPROPERTY()
	bool LifeTimerTicking = false;

	// ***** Jump timer properties *****
	// The jump timer counts up to JumpTimerMaxSeconds.

	UPROPERTY()
	FTimerHandle JumpTimerHandle;

	// How many seconds after jumping can you jump again?
	UPROPERTY()
	float JumpTimerMaxSeconds = 5;

	UPROPERTY()
	float JumpTimerSeconds;

	UPROPERTY()
	bool JumpTimerTicking = false;

	UFUNCTION()
	bool Setup();
};
