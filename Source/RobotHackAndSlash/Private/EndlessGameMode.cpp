#include "EndlessGameMode.h"

AEndlessGameMode::AEndlessGameMode()
{
    PlayerScore = 0;
}

void AEndlessGameMode::BeginPlay()
{
    Super::BeginPlay();

    // Start adding score automatically every second
    GetWorldTimerManager().SetTimer(
        ScoreTimerHandle,
        this,
        &AEndlessGameMode::IncreaseScoreOverTime,
        1.0f,
        true
    );
}

void AEndlessGameMode::AddScore(int32 Amount)
{
    PlayerScore += Amount;
    UE_LOG(LogTemp, Log, TEXT("Score: %d"), PlayerScore);
}

int32 AEndlessGameMode::GetScore() const
{
    return PlayerScore;
}

void AEndlessGameMode::IncreaseScoreOverTime()
{
    AddScore(10);
}
