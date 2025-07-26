#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "EndlessGameMode.generated.h"

UCLASS()
class ROBOTHACKANDSLASH_API AEndlessGameMode : public AGameModeBase
{
    GENERATED_BODY()

public:
    AEndlessGameMode();

    /** Current player score */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Score")
    int32 PlayerScore;

    /** Add score like Vampire Survivors */
    UFUNCTION(BlueprintCallable, Category = "Score")
    void AddScore(int32 Amount);

    /** Get current score */
    UFUNCTION(BlueprintCallable, Category = "Score")
    int32 GetScore() const;
    
    UFUNCTION()
    void IncreaseScoreOverTime();

protected:
    virtual void BeginPlay() override;
    
    FTimerHandle ScoreTimerHandle;
};