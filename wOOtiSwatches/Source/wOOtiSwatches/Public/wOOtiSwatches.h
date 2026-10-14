// Alpakit module interface. Read-only world diagnostics.
#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class UWorld;

class FwOOtiSwatchesModule : public IModuleInterface
{
public:
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;

private:
    void OnWorldBeginPlay(UWorld* World);
    FDelegateHandle WorldBeginPlayHandle;
};
