// Alpakit-generated module layout; diagnostic-only bootstrap.
#include "wOOtiSwatches.h"
#include "WootiRohOelSwatch.h"

DEFINE_LOG_CATEGORY_STATIC(LogWootiSwatches, Log, All);

void FwOOtiSwatchesModule::StartupModule()
{
    UE_LOG(LogWootiSwatches, Display, TEXT("wOOtiSwatches loaded (descriptor diagnostic; no swatches registered)."));

    // Verify the reflected descriptor type is present and has a stable Unreal class path.
    // Never allocate a game color slot during module startup.
    const UClass* RohOelClass = UWootiRohOelSwatch::StaticClass();
    if (ensureMsgf(RohOelClass != nullptr, TEXT("Rohöl descriptor reflection unavailable")))
    {
        UE_LOG(LogWootiSwatches, Display, TEXT("Rohöl identity wooti.swatch.0017; descriptor class: %s"),
            *RohOelClass->GetPathName());
    }
}

void FwOOtiSwatchesModule::ShutdownModule()
{
    UE_LOG(LogWootiSwatches, Display, TEXT("wOOtiSwatches unloaded."));
}

IMPLEMENT_MODULE(FwOOtiSwatchesModule, wOOtiSwatches)
