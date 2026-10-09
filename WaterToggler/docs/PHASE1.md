# Phase 1 — Wasser identifizieren / Identify water

[Deutsch](#deutsch) | [English](#english) | [README](../README.md)

## Deutsch

Status: Quellcode-Recherche begonnen; noch keine Runtime-Diagnose und kein getesteter Build.
Recherche vom 2026-10-09. Die geprüften Header stammen aus SML-Commit `d2162c999bbaa9650594ee9ad6e6e06190306009`; ihre Übereinstimmung mit der installierten Experimental-Version ist noch zu prüfen.

### Bestätigte Ansatzpunkte

- `AFGWaterVolume` erbt von `APhysicsVolume`.
- Die Klasse implementiert auch `IFGExtractableResourceInterface` und `IInterface_PostProcessVolume`: Wasserentnahme und Unterwasser-Postprocessing sind am selben Actor angebunden.
- Weitere Schnittstellen betreffen Navigation und Significance; Methoden betreffen Kamera- und Wasseraudio sowie Eintritts-/Austrittseffekte.
- `UFGCharacterMovementComponent` erbt von `UCharacterMovementComponent`. Im geprüften Header gibt es keine ausdrücklich benannte Water-/Swimming-Methode. Das beweist nicht, dass keine eigene Schwimmlogik existiert.

### Noch offen

Konkrete Actors, Komponenten und Materialien der sichtbaren Wasseroberfläche; ihre Beziehung zu Wasser-Volumes; die tatsächlich aktive Schwimmlogik; Unterwasser-Effekte; Verhalten beim Streaming; Kompatibilität mit der installierten Spiel-/SML-Version.

### Erste Diagnose im Spiel

Ein lesender Diagnose-Build soll in der aktiven Spielwelt erfassen:

1. Geladene `AFGWaterVolume`-Instanzen: Objektpfad, konkrete Klasse, Level, Position und Bounds.
2. Komponenten dieser Volumes: Klasse, Sichtbarkeit, Collision und gegebenenfalls Mesh-/Materialpfade.
3. Lokaler Spieler: Movement-Komponente, MovementMode und aktives PhysicsVolume — an Land, beim Eintritt ins Wasser und beim Austritt.
4. Nahe Render-Actors: Klassen, Komponenten und Materialien untersuchen, falls die Oberfläche separat vorliegt. Namen dienen nur als Suchhilfe, nicht als zuverlässiges Auswahlkriterium.
5. Unterwasser-Postprocessing und Wasseraudio getrennt zuordnen.
6. Wiederholte Erfassung nach Ortswechsel und Nachladen von Bereichen, um Streaming-Fälle sichtbar zu machen.

Keine Actor-Löschung, keine Zustandsänderungen und keine Savegame-Bearbeitung in dieser Phase.

### Entscheidung für Phase 2

Erst nach Runtime-Bestätigung gezielte Eingriffe auswählen. Derzeitige Arbeitshypothese: Rendering und Spieler-Schwimmen separat beeinflussen, während Ressourcenfunktionen erhalten bleiben. Nicht pauschal Collision oder den gesamten Volume-Actor deaktivieren. Ob diese Trennung funktioniert, ist noch nicht getestet.

Benötigt: genaue Spiel-Buildnummer, SML-Version und eine passende Modding-Entwicklungsumgebung.

## English

Status: Source research started; no runtime diagnostics or tested build yet.
Research dated 2026-10-09. Headers were inspected at SML commit `d2162c999bbaa9650594ee9ad6e6e06190306009`; compatibility with the installed Experimental version remains unverified.

### Confirmed entry points

- `AFGWaterVolume` inherits from `APhysicsVolume`.
- It also implements `IFGExtractableResourceInterface` and `IInterface_PostProcessVolume`: resource extraction and underwater postprocessing are attached to the same actor.
- Other interfaces concern navigation and significance; methods concern camera/water audio and entry/exit effects.
- `UFGCharacterMovementComponent` inherits from `UCharacterMovementComponent`. The inspected header has no explicitly named water/swimming method. This does not prove that custom swimming logic is absent.

### Open questions

Exact visible-water actors, components and materials; their relationship to water volumes; actual swimming logic; underwater effects; streaming behaviour; installed game/SML compatibility.

### First in-game diagnostics

A read-only diagnostic build should record, in the active game world:

1. Loaded `AFGWaterVolume` instances: object path, concrete class, level, position and bounds.
2. Their components: class, visibility, collision and mesh/material paths where applicable.
3. Local player: movement component, MovementMode and active PhysicsVolume on land, entering water and leaving water.
4. Nearby rendering actors: inspect classes, components and materials if surfaces are separate. Names are search hints, not reliable selection criteria.
5. Identify underwater postprocessing and water audio separately.
6. Repeat collection after travelling and loading additional areas to expose streaming cases.

No actor deletion, state changes or save-game editing during this phase.

### Phase 2 decision

Select targeted changes only after runtime confirmation. Current working hypothesis: affect rendering and player swimming separately while retaining resource functionality. Avoid disabling collision or entire volume actors indiscriminately. This separation has not been tested.

Required: exact game build number, SML version and a matching modding development environment.

## Quellen / Sources

- [FGWaterVolume.h](https://github.com/satisfactorymodding/SatisfactoryModLoader/blob/d2162c999bbaa9650594ee9ad6e6e06190306009/Source/FactoryGame/Public/FGWaterVolume.h)
- [FGCharacterMovementComponent.h](https://github.com/satisfactorymodding/SatisfactoryModLoader/blob/d2162c999bbaa9650594ee9ad6e6e06190306009/Source/FactoryGame/Public/FGCharacterMovementComponent.h)
- [Modding setup guide](https://docs.ficsit.app/satisfactory-modding/latest/Development/BeginnersGuide/index.html)
- [UnderwaterConstruction reference](https://github.com/mklierman/SatisfactoryMods/tree/main/UnderwaterConstruction)
