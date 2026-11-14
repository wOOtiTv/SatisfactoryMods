# Conveyor Belt Mk.7

[Deutsch](#deutsch) | [English](#english)

## Deutsch

Experimentelles, eigenständiges Förderband mit 3.200 Items/min als Ziel. Das Band erhält eine eigene Klasse für den gemeinsamen Einsatz mit Enhanced Conveyors. Durchsatz, Itembilanz und Kompatibilität sind offen.

1. Das Verzeichnis ConveyorBeltMk7 nach Mods im lokalen SML-Projekt kopieren. Plugin und Python Editor Script Plugin im CSS-Unreal-Editor aktivieren und den Editor neu starten.
2. Tools/generate_assets.py im Editor ausführen. Der Generator dupliziert die Mk.6-Vorlagen, setzt den eigenen Geschwindigkeitswert relativ zum Vanilla-Mk.6 und verbindet Band und Deskriptor. Bauteilkosten und Optik stammen für den Start vom Mk.6. Falls ein Lauf teilweise fehlschlägt, die erzeugten Assets im Editor prüfen, bevor der Generator erneut läuft.
3. In einem eigenen FGSchematic das Rezept Recipe_ConveyorBeltMk7 freischalten. Das Schematic im RootGameWorld des Plugins unter M Schematics registrieren. Die Anzeigen im Baumenü, Upgrade-Zuordnung und Hologramm im Editor prüfen und mit Alpakit paketieren.
4. In einem Testspielstand mit Enhanced Conveyors die beiden Bandstufen messen. Für Mk.7 ausreichend parallele Ein- und Ausgänge bereitstellen. Nach dem Anlaufen über mehrere Minuten sowohl Durchsatz als auch Itembilanz prüfen und bei unterschiedlichen Bildraten wiederholen.

Stand: Band, Deskriptor und verknüpftes Baurezept im CSS-Editor gespeichert. Freischaltung, Paketierung und Ingame-Test stehen aus.

## English

Experimental standalone belt targeting 3,200 items/min. It uses a separate buildable class for coexistence with Enhanced Conveyors. Throughput, item conservation and compatibility are unverified.

1. Copy ConveyorBeltMk7 into the local SML project's Mods directory. Enable the plugin and Python Editor Script Plugin in the CSS Unreal Editor and restart.
2. Run Tools/generate_assets.py in the editor. It duplicates the vanilla Mk.6 templates, scales the speed relative to vanilla Mk.6 and connects the belt and descriptor. The initial cost and appearance come from Mk.6. If generation fails partway, inspect the generated assets before running again.
3. Create a dedicated FGSchematic unlocking Recipe_ConveyorBeltMk7 and register it in the plugin's RootGameWorld under M Schematics. Check the build-menu labels, upgrade mapping and hologram before packaging with Alpakit.
4. Measure both belt tiers in a test save with Enhanced Conveyors enabled. Provide adequate parallel inputs and outputs. After warm-up, check actual throughput and item balance over several minutes and repeat at different frame rates.

Status: Belt, descriptor and linked build recipe saved in the CSS editor. Unlock, packaging and game validation are pending.

[Reference mod and throughput observations](https://github.com/budak7273/BeltMk6) · [SML schematic guide](https://docs.ficsit.app/satisfactory-modding/latest/Development/BeginnersGuide/SimpleMod/recipe.html)
