# wOOtiSwatches

[Deutsch](#deutsch) | [English](#english)

## Deutsch

**Status: Konzept / Entwicklungsvorbereitung – keine installierbare Mod.**

wOOtiSwatches soll eine eigenständige, schlanke Farb-Mod für Satisfactory werden, inspiriert vom Ansatz von [Universal Swatch Slots](https://github.com/Loupimo/UniversalSwatchSlots) (USS). Ziel ist eine einzige eigene Palette ohne die umfangreiche USS-Standardpalette.

### Anforderungen

- Die 18 Vanilla-Farbslots bleiben unverändert.
- Eine separate **wOOti Palette** mit genau den gewünschten Farben; keine automatische USS-Default-Palette.
- Alphabetische Farbnamen in Deutsch.
- Änderungen an selbst definierten Farben sollen einen Spielneustart überstehen; Speichermechanismus und Verhalten bei bestehenden Gebäuden sind noch zu implementieren und zu testen.
- Bestehende Spielstände nur mit Backup und Testsave migrieren; alte USS-Presets können im Save bleiben.
- Keine Laufzeit-Abhängigkeit von USS als Ziel; technische Implementierung noch offen.

### Produktionspalette (Originalwerte)

Die folgende Tabelle stammt aus der bereitgestellten `wOOti_Palette_Produktion.json`. Primär- und Sekundärfarben haben aktuell jeweils denselben Wert. Die Quelldatei wird **unverändert inhaltlich** als Referenz unter `config/wOOti_Palette_Produktion.json` geführt. Sie ist noch **kein** nachgewiesenes Config-Format für die künftige eigenständige Mod.

| Farbe | Primär | Sekundär |
| --- | --- | --- |
| Aluminium | `#9b9d9e` | `#9b9d9e` |
| Bauxit | `#a56a56` | `#a56a56` |
| Bernstein | `#F2AA00FF` | `#F2AA00FF` |
| Dunkelgrau | `#424242FF` | `#424242FF` |
| Dunkle Materie Rückstand | `#FDAFF9FF` | `#FDAFF9FF` |
| Gummi | `#353232` | `#353232` |
| Hellgrau | `#BCBCBCFF` | `#BCBCBCFF` |
| Ionisierter Treibstoff | `#D55F1AFF` | `#D55F1AFF` |
| Kalkstein | `#908277` | `#908277` |
| Kunststoff | `#4dacf0` | `#4dacf0` |
| Orange | `#F39C27FF` | `#F39C27FF` |
| Petrol | `#0D3A3DFF` | `#0D3A3DFF` |
| Photonische Materie | `#76F5E8FF` | `#76F5E8FF` |
| Quarz | `#cf9bcf` | `#cf9bcf` |
| Quarzsand | `#E7DFCFFF` | `#E7DFCFFF` |
| Raketentreibstoff | `#BD251AFF` | `#BD251AFF` |
| Rohöl | `#190019` | `#190019` |
| Salpetersäure | `#d9d9a2` | `#d9d9a2` |
| SAM | `#65369c` | `#65369c` |
| Schrauben | `#3361B3FF` | `#3361B3FF` |
| Schwefel | `#d0b955` | `#d0b955` |
| Schwerölrückstand | `#6d2d78` | `#6d2d78` |
| Stickstoff | `#C1C1C1FF` | `#C1C1C1FF` |
| Treibstoff | `#eb7d15` | `#eb7d15` |
| Turbotreibstoff | `#A00000FF` | `#A00000FF` |
| Uran | `#88d188` | `#88d188` |
| Wasser | `#84A4D0FF` | `#84A4D0FF` |

### Nächste technische Schritte

1. Satisfactory-/SML-Versionen und Modding-Toolchain prüfen.
2. USS-Registrierung, UI-Erweiterung und Preset-Speicherung analysieren; keine 1:1-Portierung voraussetzen.
3. Eigenständige Swatch-Registrierung und persistent gespeicherte Farbwerte implementieren.
4. Verhalten beim Neustart, in vorhandenen Saves und beim Wechsel von USS in einem Testsave prüfen.
5. Lizenz- und Attribution-Anforderungen beachten, falls USS-Quellcode übernommen wird (USS: GPL-3.0).

## English

**Status: concept / development preparation – not an installable mod.**

wOOtiSwatches aims to provide one small, independent Satisfactory color palette inspired by Universal Swatch Slots, without its large default collection. The 18 vanilla color slots must remain untouched. User edits should persist across restarts, subject to implementation and testing. The JSON under `config/` is reference data, **not** a verified configuration format for the eventual standalone plugin.

### Palette

The 27 original names and hex values are listed in the German section above.

### Development

Investigate Satisfactory/SML compatibility, swatch registration, UI behavior, persistence and safe migration from USS. Test with backed-up saves. If any USS source code is reused, comply with its GPL-3.0 license.
