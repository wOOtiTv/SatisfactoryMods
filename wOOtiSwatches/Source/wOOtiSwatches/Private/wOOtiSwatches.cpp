#include "Modules/ModuleManager.h"
#include "Misc/Paths.h"

DEFINE_LOG_CATEGORY_STATIC(LogWootiSwatches, Log, All);

class FWootiSwatchesModule final : public IModuleInterface
{
public:
    virtual void StartupModule() override
    {
        // Bootstrap only. No swatch registration and no world/save mutations.
        UE_LOG(LogWootiSwatches, Display,
            TEXT("wOOtiSwatches development module loaded. No game swatches registered."));
    }

    virtual void ShutdownModule() override
    {
        UE_LOG(LogWootiSwatches, Display, TEXT("wOOtiSwatches module unloaded."));
    }
};

IMPLEMENT_MODULE(FWootiSwatchesModule, wOOtiSwatches)
