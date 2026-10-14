// Read-only swatch slot diagnostics. No game-state writes or save changes.
#include "wOOtiSwatches.h"
#include "WootiRohOelSwatch.h"
#include "Engine/World.h"
#include "FGGameState.h"
#include "FGBuildableSubsystem.h"

DEFINE_LOG_CATEGORY_STATIC(LogWootiSwatches, Log, All);

void FwOOtiSwatchesModule::StartupModule()
{
    UE_LOG(LogWootiSwatches, Display, TEXT("wOOtiSwatches loaded (read-only world diagnostics)."));

    const UClass* RohOelClass = UWootiRohOelSwatch::StaticClass();
    if (RohOelClass)
    {
        UE_LOG(LogWootiSwatches, Display,
            TEXT("Rohöl identity wooti.swatch.0017; descriptor class: %s"),
            *RohOelClass->GetPathName());
    }

    WorldBeginPlayHandle = FWorldDelegates::OnWorldBeginPlay.AddRaw(
        this, &FwOOtiSwatchesModule::OnWorldBeginPlay);
}

void FwOOtiSwatchesModule::OnWorldBeginPlay(UWorld* World)
{
    if (!World || !World->IsGameWorld())
    {
        return;
    }

    UE_LOG(LogWootiSwatches, Display, TEXT("[Slots] World begin play: %s"),
        *World->GetName());

    const AFGGameState* GameState = World->GetGameState<AFGGameState>();
    const AFGBuildableSubsystem* Buildables = AFGBuildableSubsystem::Get(World);

    if (!GameState)
    {
        UE_LOG(LogWootiSwatches, Warning,
            TEXT("[Slots] GameState not available at BeginPlay; no conclusion about slots."));
    }
    else
    {
        UE_LOG(LogWootiSwatches, Display, TEXT("[Slots] GameState slot count: %d"),
            GameState->mBuildingColorSlots_Data.Num());
    }

    if (!Buildables)
    {
        UE_LOG(LogWootiSwatches, Warning,
            TEXT("[Slots] BuildableSubsystem not available at BeginPlay; no conclusion about slots."));
    }
    else
    {
        UE_LOG(LogWootiSwatches, Display, TEXT("[Slots] BuildableSubsystem slot count: %d"),
            Buildables->mColorSlots_Data.Num());
    }

    // Array length alone does NOT establish ownership or safety of a slot.
    // These indices are observations only; other mods may initialize later.
    for (int32 Slot = 24; Slot <= 31; ++Slot)
    {
        const bool bGameStatePresent = GameState &&
            GameState->mBuildingColorSlots_Data.IsValidIndex(Slot);
        const bool bBuildablePresent = Buildables &&
            Buildables->mColorSlots_Data.IsValidIndex(Slot);
        UE_LOG(LogWootiSwatches, Display,
            TEXT("[Slots] index=%d gameStatePresent=%s buildablePresent=%s (not a free-slot test)"),
            Slot, bGameStatePresent ? TEXT("yes") : TEXT("no"),
            bBuildablePresent ? TEXT("yes") : TEXT("no"));
    }
}

void FwOOtiSwatchesModule::ShutdownModule()
{
    if (WorldBeginPlayHandle.IsValid())
    {
        FWorldDelegates::OnWorldBeginPlay.Remove(WorldBeginPlayHandle);
        WorldBeginPlayHandle.Reset();
    }
    UE_LOG(LogWootiSwatches, Display, TEXT("wOOtiSwatches unloaded."));
}

IMPLEMENT_MODULE(FwOOtiSwatchesModule, wOOtiSwatches)
