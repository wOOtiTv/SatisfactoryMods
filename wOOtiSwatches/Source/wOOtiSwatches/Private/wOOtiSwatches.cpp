// Safe bootstrap: descriptor reflection only. No engine slot access or mutations.
#include "wOOtiSwatches.h"
#include "WootiRohOelSwatch.h"

DEFINE_LOG_CATEGORY_STATIC(LogWootiSwatches, Log, All);

void FwOOtiSwatchesModule::StartupModule()
{
    UE_LOG(LogWootiSwatches, Display, TEXT("wOOtiSwatches loaded (safe diagnostic bootstrap)."));

    const UClass* RohOelClass = UWootiRohOelSwatch::StaticClass();
    if (RohOelClass)
    {
        UE_LOG(LogWootiSwatches, Display,
            TEXT("Rohöl identity wooti.swatch.0017; descriptor class: %s"),
            *RohOelClass->GetPathName());
    }

    UE_LOG(LogWootiSwatches, Display,
        TEXT("[Slots] Diagnosis deferred: game color arrays are private in current FactoryGame headers."));
}

void FwOOtiSwatchesModule::ShutdownModule()
{
    UE_LOG(LogWootiSwatches, Display, TEXT("wOOtiSwatches unloaded."));
}

IMPLEMENT_MODULE(FwOOtiSwatchesModule, wOOtiSwatches)
