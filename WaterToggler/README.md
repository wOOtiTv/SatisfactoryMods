# WaterToggler 🌊

[Deutsch](#deutsch) | [English](#english) | [Changelog](CHANGELOG.md)

## Deutsch

[Phase 1: Recherche und Runtime-Diagnose](docs/PHASE1.md#deutsch)

**Ziel:** Ein temporärer **Dry-Build-Mode**, um Bauarbeiten auf dem Meeresboden zu erleichtern.

> Status: Konzept und technische Recherche. Noch kein installierbarer Mod-Build.

### Gewünschtes Verhalten

| Funktion | Wasser AN | Wasser AUS |
| --- | --- | --- |
| Wasseroberfläche | sichtbar | unsichtbar |
| Spieler-Schwimmen | normal | unterbunden |
| Meeresboden | unter Wasser | für Bauarbeiten sichtbar |
| Gebäude und Fundamente | unverändert | normal platzierbar |
| Water Extractors | normal | möglichst unverändert |
| Savegame | unverändert | keine dauerhafte Wasser-Manipulation |

Der Toggle soll zunächst im Singleplayer funktionieren, später möglichst per Hotkey oder Mod-Einstellung.

### Proof of Concept

- [ ] Aktuelle Wasser-Actors, Komponenten und Streaming-Verhalten der Spielversion untersuchen
- [ ] Renderer und Schwimm-Volumes getrennt analysieren
- [ ] Temporäres Ausblenden und Wiederherstellen der Wasseroberfläche testen
- [ ] Schwimmmechanik unterbinden und danach korrekt wiederherstellen
- [ ] Normales Bauen und Kollision am Meeresboden testen
- [ ] Water Extractors und andere wasserabhängige Systeme prüfen
- [ ] World-Partition-/Streaming- und Respawn-Fälle testen
- [ ] Hotkey/UI ergänzen

### Technische Leitplanken

Kein Löschen von World-Actors, keine Savegame-Bearbeitung. Originalzustände bei Änderungen merken und zuverlässig wiederherstellen. Render-, Movement- und Build-Verhalten getrennt behandeln. Ein Testsave ist Pflicht.

### Recherche: UnderwaterConstruction

Quelle: [mklierman/SatisfactoryMods – UnderwaterConstruction](https://github.com/mklierman/SatisfactoryMods/tree/main/UnderwaterConstruction) von SirDigby.

Der C++-Quellcode registriert mit `SUBSCRIBE_METHOD` Hooks für `AFGCharacterPlayer::CanEquipBuildGun`, `CanEquipBuildGunForDismantle` und `CanEquipBuildGunForPaint`. Wenn der Character-Movement-Mode `MOVE_Swimming` ist, wird mit `scope.Override(true)` die Nutzung des Bauwerkzeugs erlaubt.

**Wichtig:** Dieses Projekt blendet Wasser nicht aus und deaktiviert nicht das Schwimmen. Es ist eine Referenz für mögliche Bau-Interaktionen, kein fertiger Water-Toggle.

Die aktuelle Kompatibilität mit Satisfactory Experimental wurde noch nicht geprüft. Kein fremder Quellcode wurde hier kopiert.

## English

[Phase 1: Research and runtime diagnostics](docs/PHASE1.md#english)

**Goal:** A temporary **dry-build mode** to make construction on the seabed easier.

> Status: Concept and technical research. No installable mod build yet.

### Desired behaviour

| Feature | Water ON | Water OFF |
| --- | --- | --- |
| Water surface | visible | hidden |
| Player swimming | normal | disabled |
| Seabed | underwater | visible for construction |
| Buildings and foundations | unchanged | can be placed normally |
| Water Extractors | normal | unchanged where possible |
| Save game | unchanged | no permanent water modifications |

The toggle should initially work in singleplayer, with a hotkey or mod setting added later if possible.

### Proof of concept

- [ ] Investigate the current game version's water actors, components and streaming behaviour
- [ ] Analyse rendering and swimming volumes separately
- [ ] Test temporarily hiding and restoring the water surface
- [ ] Disable swimming and restore it correctly afterwards
- [ ] Test normal construction and collision on the seabed
- [ ] Check Water Extractors and other water-dependent systems
- [ ] Test World Partition, streaming and respawn cases
- [ ] Add a hotkey/UI

### Technical constraints

Do not delete world actors or edit save games. Record original states before changes and restore them reliably. Handle rendering, movement and construction behaviour separately. A test save is required.

### Research: UnderwaterConstruction

Source: [mklierman/SatisfactoryMods – UnderwaterConstruction](https://github.com/mklierman/SatisfactoryMods/tree/main/UnderwaterConstruction) by SirDigby.

The C++ source registers `SUBSCRIBE_METHOD` hooks for `AFGCharacterPlayer::CanEquipBuildGun`, `CanEquipBuildGunForDismantle` and `CanEquipBuildGunForPaint`. When the character movement mode is `MOVE_Swimming`, `scope.Override(true)` allows use of the build tool.

**Important:** This project does not hide water or disable swimming. It is a reference for possible construction interactions, not a complete water toggle.

Compatibility with the current Satisfactory Experimental version has not been checked. No external source code has been copied into this project.
