# WaterToggler 🌊

**Ziel:** Ein temporärer **Dry-Build-Mode**, um Bauarbeiten auf dem Meeresboden zu erleichtern.

> Status: Konzept und technische Recherche. Noch kein installierbarer Mod-Build.

## Gewünschtes Verhalten

| Funktion | Wasser AN | Wasser AUS |
| --- | --- | --- |
| Wasseroberfläche | sichtbar | unsichtbar |
| Spieler-Schwimmen | normal | unterbunden |
| Meeresboden | unter Wasser | für Bauarbeiten sichtbar |
| Gebäude und Fundamente | unverändert | normal platzierbar |
| Water Extractors | normal | möglichst unverändert |
| Savegame | unverändert | keine dauerhafte Wasser-Manipulation |

Der Toggle soll zunächst im Singleplayer funktionieren, später möglichst per Hotkey oder Mod-Einstellung.

## Proof of Concept

- [ ] Aktuelle Wasser-Actors, Komponenten und Streaming-Verhalten der Spielversion untersuchen
- [ ] Renderer und Schwimm-Volumes getrennt analysieren
- [ ] Temporäres Ausblenden und Wiederherstellen der Wasseroberfläche testen
- [ ] Schwimmmechanik unterbinden und danach korrekt wiederherstellen
- [ ] Normales Bauen und Kollision am Meeresboden testen
- [ ] Water Extractors und andere wasserabhängige Systeme prüfen
- [ ] World-Partition-/Streaming- und Respawn-Fälle testen
- [ ] Hotkey/UI ergänzen

## Technische Leitplanken

Kein Löschen von World-Actors, keine Savegame-Bearbeitung. Originalzustände bei Änderungen merken und zuverlässig wiederherstellen. Render-, Movement- und Build-Verhalten getrennt behandeln. Ein Testsave ist Pflicht.

## Recherche: UnderwaterConstruction

Quelle: [mklierman/SatisfactoryMods – UnderwaterConstruction](https://github.com/mklierman/SatisfactoryMods/tree/main/UnderwaterConstruction) von SirDigby.

Der C++-Quellcode registriert mit `SUBSCRIBE_METHOD` Hooks für `AFGCharacterPlayer::CanEquipBuildGun`, `CanEquipBuildGunForDismantle` und `CanEquipBuildGunForPaint`. Wenn der Character-Movement-Mode `MOVE_Swimming` ist, wird mit `scope.Override(true)` die Nutzung des Bauwerkzeugs erlaubt.

**Wichtig:** Dieses Projekt blendet Wasser nicht aus und deaktiviert nicht das Schwimmen. Es ist eine Referenz für mögliche Bau-Interaktionen, kein fertiger Water-Toggle.

Die aktuelle Kompatibilität mit Satisfactory Experimental wurde noch nicht geprüft. Kein fremder Quellcode wurde hier kopiert.
