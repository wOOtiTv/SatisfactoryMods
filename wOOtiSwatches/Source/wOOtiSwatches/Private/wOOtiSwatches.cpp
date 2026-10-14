// Alpakit-generated module layout; bootstrap logging only.
#include "wOOtiSwatches.h"

DEFINE_LOG_CATEGORY_STATIC(LogWootiSwatches, Log, All);

void FwOOtiSwatchesModule::StartupModule()
{
    UE_LOG(LogWootiSwatches, Display, TEXT("wOOtiSwatches loaded (bootstrap only; no swatches registered)."));
}

void FwOOtiSwatchesModule::ShutdownModule()
{
    UE_LOG(LogWootiSwatches, Display, TEXT("wOOtiSwatches unloaded."));
}

IMPLEMENT_MODULE(FwOOtiSwatchesModule, wOOtiSwatches)
