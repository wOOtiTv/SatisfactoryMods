#pragma once

#include "CoreMinimal.h"
#include "Subsystem/ModSubsystem.h"
#include "WootiSwatchesDiagnosticSubsystem.generated.h"

/**
 * Read-only color diagnostic. Register in the Game World Module's
 * "Mod Subsystems" array; declaration alone does not spawn this actor.
 */
UCLASS(Blueprintable)
class WOOTISWATCHES_API AWootiSwatchesDiagnosticSubsystem : public AModSubsystem
{
    GENERATED_BODY()

protected:
    virtual void Init() override;
    virtual void BeginPlay() override;
};
