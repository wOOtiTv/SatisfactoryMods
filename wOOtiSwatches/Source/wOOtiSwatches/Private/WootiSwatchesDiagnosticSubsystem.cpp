#include "WootiSwatchesDiagnosticSubsystem.h"

#include "FGBuildableSubsystem.h"
#include "FGGameState.h"
#include "Engine/World.h"

DEFINE_LOG_CATEGORY_STATIC(LogWootiSlotProbe, Log, All);

void AWootiSwatchesDiagnosticSubsystem::BeginPlay()
{
    Super::BeginPlay();

    UWorld* World = GetWorld();
    if (!World || !World->IsGameWorld())
    {
        return;
    }

    AFGGameState* GameState = World->GetGameState<AFGGameState>();
    AFGBuildableSubsystem* Buildables = AFGBuildableSubsystem::Get(World);
    UE_LOG(LogWootiSlotProbe, Display, TEXT("[Slots] Diagnostic subsystem BeginPlay; world=%s"),
        *World->GetName());

    if (!GameState || !Buildables)
    {
        UE_LOG(LogWootiSlotProbe, Warning,
            TEXT("[Slots] Not ready at BeginPlay: GameState=%s Buildables=%s"),
            GameState ? TEXT("yes") : TEXT("no"),
            Buildables ? TEXT("yes") : TEXT("no"));
        return;
    }

    // Only inspect a known existing vanilla slot (index 0).
    // Do not query indices >= 28 without confirming their allocation semantics.
    const FFactoryCustomizationColorSlot& Color = Buildables->GetColorSlot_Data(uint8(0));
    const FFactoryCustomizationColorSlot SavedColor = GameState->GetBuildingColorDataForSlot(uint8(0));
    UE_LOG(LogWootiSlotProbe, Display,
        TEXT("[Slots] Vanilla slot 0 read via public APIs; buildablePrimary=(%.3f,%.3f,%.3f) gameStatePrimary=(%.3f,%.3f,%.3f)"),
        Color.PrimaryColor.R, Color.PrimaryColor.G, Color.PrimaryColor.B,
        SavedColor.PrimaryColor.R, SavedColor.PrimaryColor.G, SavedColor.PrimaryColor.B);
    UE_LOG(LogWootiSlotProbe, Display,
        TEXT("[Slots] Read-only diagnostic complete; no slot allocation or changes."));
}
