# Changelog – wOOtiSwatches

[Deutsch](#deutsch) | [English](#english)

## Deutsch

### Unreleased

- Erste fest benannte C++-Descriptor-Klasse `UWootiRohOelSwatch` für Rohöl (`wooti.swatch.0017`) angelegt; noch ohne Registrierung oder Slotnummer. Nächster Schritt: lokaler Kompiliertest.

- Minimales Unreal-/SML-C++-Modulgerüst mit Plugin-Descriptor, Build.cs und Start/Stop-Logging angelegt.
- Build-/Testprotokoll ergänzt; noch keine Farbregistrierung und kein erfolgreicher Build nachgewiesen.

- Stabilen JSON-Katalog für 27 Farben und unveränderliche Kennungen angelegt (`swatches.json`, `ids.lock.json`).
- Validierung für ID-Kollisionen, versehentliches Umbenennen/Entfernen und alphabetisch eingefügte Farben ergänzt.
- Technische Zuordnung zu tatsächlichen Satisfactory-Swatch-Assets und Savegames noch nicht umgesetzt.

- Entwicklungsverzeichnis und Projektdokumentation für wOOtiSwatches angelegt.
- Originale Produktionspalette mit 27 Farben als Referenz aufgenommen.
- Anforderungen an getrennte Vanilla-Slots, schlanken Farbwähler und persistente Änderungen festgehalten.
- Noch keine funktionsfähige Mod erstellt oder im Spiel getestet.

## English

### Unreleased

- Added a stable Rohöl C++ descriptor class for compilation testing, not yet registered in-game.
- Added an Unreal/SML C++ module bootstrap and build/test protocol; uncompiled, not game-tested, and not registering swatches yet.
- Added a stable-ID catalog and locked identity registry for the initial 27 colors.
- Added validation for identity reassignment, removal and alphabetically inserted new colors.
- Runtime asset registration and save persistence are not implemented yet.
- Added initial project documentation and the original 27-color production palette as reference data.
- Defined requirements for untouched vanilla slots, a compact picker, and persistent edits.
- No working game mod or in-game test yet.
