# Technische Analyse: Farbslots, Persistenz und Migration

Stand: 2026-10-14. **Recherche / Architektur, kein ausführbarer Satisfactory-Code.**

## Erkenntnisse aus USS (Quellenanalyse)

Referenz: [UniversalSwatchSlots](https://github.com/Loupimo/UniversalSwatchSlots), insbesondere [UniversalSwatchSlotsSubsystem.cpp](https://github.com/Loupimo/UniversalSwatchSlots/blob/main/Source/UniversalSwatchSlots/Private/UniversalSwatchSlotsSubsystem.cpp) und [UniversalSwatchSlotsDefinitions.h](https://github.com/Loupimo/UniversalSwatchSlots/blob/main/Source/UniversalSwatchSlots/Public/UniversalSwatchSlotsDefinitions.h).

- `RetrieveFreeColorSlotID` beginnt bei Index **28** (nach den Vanilla-/Spezialslots 0–27) und berücksichtigt Slots anderer Mods über `ExternalAddedSwatches`. Index **255** ist für Custom reserviert; der Code nutzt einen `uint8`-Slotindex. **Keine unbegrenzte Anzahl von Spielslots behaupten.**
- `GenerateDynamicSwatchDescriptor` erzeugt eine Descriptor-Klasse samt dynamischem Namen (bei USS u. a. `Gen_USS_SwatchDesc_<SlotID>_Class`); das Objekt enthält Slot-ID, Farben, Anzeigename und Kategorie.
- Die USS-Palette vergibt laufende freie Slot-IDs: eine andere Palette-/Mod-Reihenfolge kann Slots verschieben. USS versucht über gespeicherte Informationen (u. a. `SwatchSlotID`, `SwatchGeneratedName`) alte Zuordnungen zu finden.
- `PatchBuildingsSwatchDescriptor` remappt `FFactoryCustomizationData` bei Actor-Buildables **und** Lightweight-Instanzen. Wichtig: Ein Cache kann sonst eine veraltete Farbe anzeigen, obwohl Descriptor/Slot bereits geändert sind.
- `AddNewSwatchesColorSlotsToGameState` berücksichtigt `AFGGameState`, `AFGBuildableSubsystem`, Server-Autorität und Client-Replikation. Ein reines Überschreiben der JSON-Startfarben ist deshalb kein Persistenzkonzept.
- `UpdateSavedSwatches` verwaltet SaveGame-Informationen für bisherige Slotzuordnungen und Farben. Bei fehlender Palette warnt USS vor Verlust/Ersetzung alter Farben.

## Architekturentscheidung für wOOtiSwatches

**Drei getrennte Ebenen:**

1. **Katalog-Identität:** `wooti.swatch.0001` etc. ist die **logische** dauerhafte ID in `config/swatches.json`. Keine Beziehung zur Sortierposition.
2. **Engine-Identität:** Ein stabiler, deterministisch erzeugter Descriptor-Pfad und eine für den Spielstand reservierte Slot-Nummer. Die Abbildung `logical ID -> engine descriptor/slot` darf sich für bereits verwendete Farben nie still ändern.
3. **Angezeigte Reihenfolge:** Nach Farbe/Anzeigename sortieren, ohne IDs oder Engine-Slots umzunummerieren.

**Noch nicht entschieden:** Welche Engine-Slots tatsächlich sicher frei sind, wie Mod-Konflikte verhindert werden und wie stabil der Descriptor-Pfad über Spielstarts hinweg garantiert werden kann. Daher **jetzt keine** willkürlichen Slotnummern 28–54 in die JSON schreiben.

**Speicherregel:** Die JSON legt **nur Standardwerte für neue** Swatches/Spielstände fest. Vorhandene, vom Spieler bearbeitete Farbwerte aus dem Save haben beim Laden Vorrang. Fehlende ID bedeutet keine automatische Wiederverwendung des Platzes; alte IDs bleiben reserviert. Änderungen an einzelnen Farben sollen weiterhin auf ihre stabilen Slot-/Descriptor-Referenzen zeigen.

## Testmatrix vor Installation im Produktivsave

| Fall | Erwartetes Ergebnis |
| --- | --- |
| Spiel laden → Rohöl einfärben → speichern → neu starten | Gebäude bleibt Rohöl |
| Rohöl-Farbwerte ändern → speichern → neu starten | geänderte Farbe bleibt |
| Neue Farbe alphabetisch vor Aluminium ergänzen | bestehende IDs und Gebäude unverändert |
| Farbe umbenennen | logische ID, Engine-Descriptor und Slot unverändert |
| Farbe aus aktueller Ansicht entfernen | historische ID reserviert, Gebäude nicht auf eine andere Farbe legen |
| Vanilla-Farbslots prüfen | keine Veränderung |
| Mit zusätzlicher Swatch-Mod | keine Slot-Kollision, sonst sicher abbrechen |
| Multiplayer-Join | Serverdaten korrekt repliziert, keine veralteten Farben |
| Actor- und Lightweight-Bauteile | identische Farben vor/nach Neustart |
| USS-Save zu wOOtiSwatches migrieren | nur nach explizitem Backup; automatische sichere Migration **nicht zugesichert** |

## Nächster Implementierungsschritt

Im bestehenden SML/FactoryGame-Toolchain-Projekt ein minimales eigenes **wOOtiSwatches**-Modul anlegen, zunächst mit **einem** Testswatch (nicht produktive 27). Descriptor-Registrierung, Slot-Kollisionen und Speichern/Neuladen im Testsave nachweisen. Erst danach die 27 Einträge automatisiert registrieren und das Customizer-UI bereinigen.

**Quellcode-Lizenz:** Dieser Text fasst das Vorgehen zusammen; es wurde **kein USS-C++-Quellcode kopiert**. Bei späterer Übernahme müssen Lizenzpflichten der GPL-3.0 geprüft und erfüllt werden.
