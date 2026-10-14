# Build- und Testprotokoll / Build and test protocol

## Deutsch

**Status:** Modul und Rohöl-Descriptor wurden lokal erfolgreich kompiliert und im Editor geladen (Nutzer-Log vom 14.10.2026). Neue read-only World-Slot-Diagnose ist noch nicht lokal gebaut/getestet.

### Aufbau

- `wOOtiSwatches.uplugin`: Unreal-Plugin-Descriptor (Entwicklungsversion).
- `Source/wOOtiSwatches/wOOtiSwatches.Build.cs`: Abhängigkeiten für das C++-Modul.
- `Source/wOOtiSwatches/Private/wOOtiSwatches.cpp`: nur Modul-Start/Stop mit Log-Ausgaben.
- **Es existieren noch keine registrierten Swatches im Spiel.** Rohöl ist als erstes Test-Swatch im JSON-Katalog vorbereitet.

### Nächster lokaler Prüfpunkt

1. Im vorhandenen SatisfactoryModLoader-/FactoryGame-Projekt feststellen, welche SML-, UE- und Game-Version aktuell vorhanden sind.
2. Plugin für die jeweilige Toolchain korrekt einbinden (üblicherweise im Plugin-Kontext des Modding-Projekts, **nicht** direkt im produktiven Steam-Mods-Ordner).
3. Projektdateien regenerieren, Entwicklungs-Build durchführen und eventuelle Compiler-/SML-Fehler dokumentieren.
4. Ein separates Testsave verwenden; das Produktivsave nicht mit dem Prototyp öffnen.
5. Im Log die Meldung `wOOtiSwatches development module loaded` nachweisen.
6. **Danach** Rohöl-Descriptor, Slot-Kollisionsprüfung und Savegame-Persistenz implementieren. Keine Slotnummer aus Vermutungen hartkodieren.

Keine behauptete SML-Mindestversion oder Spielversionskompatibilität, bis der erste Build die Angaben bestätigt.

## English

**Status:** C++ module bootstrap only; not built, installed or tested. It logs module startup/shutdown but intentionally registers no swatches and changes no savegame state. Verify the current local FactoryGame/SML toolchain before building, then use a disposable test save.


## Read-only Slotdiagnose (14.10.2026)

Im Modul ist ein `FWorldDelegates::OnWorldBeginPlay`-Callback implementiert. Er liest bei Spielwelt-Beginn die Anzahl der Farbslots im `AFGGameState` und im `AFGBuildableSubsystem` und protokolliert für Indizes 24–31, ob Arrayeinträge existieren.

- **Keine** Vergabe, Registrierung oder Veränderung von Farben/Slots.
- **Keine** sichere Feststellung, ob ein Slot frei ist: Array-Länge/Existenz sagen nichts über Eigentümer aus, und andere Mods können später initialisieren.
- Nur Spielwelten werden untersucht; reines Öffnen des Editors ohne Play löst die Abfrage nicht aus.
- Für den Test: Plugin lokal synchronisieren, Editor-Build durchführen, Editor starten, **separates Testsave oder PIE** öffnen und im Output Log nach `[Slots]` suchen.
- Test noch ausstehend; eventuelle Buildfehler in dieser SML-/Engine-Version müssen anhand des lokalen Compiler-Logs korrigiert werden.
