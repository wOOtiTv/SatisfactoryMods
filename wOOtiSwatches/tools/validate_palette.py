#!/usr/bin/env python3
"""Validate stable wOOtiSwatches catalog identities. No game-runtime integration yet."""
import copy
import json
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
CONFIG = ROOT / "config"
ID_PATTERN = re.compile(r"wooti\.swatch\.[0-9]{4,}$")
HEX_PATTERN = re.compile(r"#[0-9A-Fa-f]{6}(?:[0-9A-Fa-f]{2})?$")


def validate(manifest, lock):
    errors = []
    swatches = manifest.get("swatches", [])
    registry = lock.get("ids", {})
    if manifest.get("schemaVersion") != 1 or lock.get("schemaVersion") != 1:
        errors.append("Unsupported schema version")
    if not isinstance(swatches, list) or not isinstance(registry, dict):
        return ["Invalid catalog shape"]
    seen_ids, seen_names = set(), set()
    for item in swatches:
        sid = item.get("id", "")
        name = item.get("name", "")
        if not isinstance(sid, str) or not ID_PATTERN.fullmatch(sid):
            errors.append(f"Invalid stable id: {sid!r}")
        if sid in seen_ids:
            errors.append(f"Duplicate ID: {sid}")
        if name in seen_names:
            errors.append(f"Duplicate display name: {name}")
        seen_ids.add(sid)
        seen_names.add(name)
        if sid in registry and registry[sid] != name:
            errors.append(f"Identity reassigned: {sid} used to mean {registry[sid]!r}, now {name!r}")
        if sid not in registry:
            errors.append(f"New ID {sid} must be added to ids.lock.json")
        for prop in ("primary", "secondary"):
            color = item.get(prop, "")
            if not isinstance(color, str) or not HEX_PATTERN.fullmatch(color):
                errors.append(f"Invalid {prop} color for {name!r}: {color!r}")
    for sid, name in registry.items():
        if sid not in seen_ids:
            errors.append(f"Registered identity removed: {sid} ({name}) — keep as reserved; plan migration")
    return errors


def main():
    manifest = json.loads((CONFIG / "swatches.json").read_text(encoding="utf-8"))
    lock = json.loads((CONFIG / "ids.lock.json").read_text(encoding="utf-8"))
    assert not validate(manifest, lock), validate(manifest, lock)

    # A new alphabetically earlier color may alter display ordering, never existing identities.
    expanded = copy.deepcopy(manifest)
    expanded["swatches"].insert(0, {
        "id": "wooti.swatch.0028",
        "name": "Aardvark (test only)",
        "primary": "#123456",
        "secondary": "#123456",
        "material": "Default"
    })
    expanded_lock = copy.deepcopy(lock)
    expanded_lock["ids"]["wooti.swatch.0028"] = "Aardvark (test only)"
    assert not validate(expanded, expanded_lock)
    assert {s["name"]: s["id"] for s in manifest["swatches"]} == {
        s["name"]: s["id"] for s in expanded["swatches"] if s["id"] != "wooti.swatch.0028"
    }
    swapped = copy.deepcopy(manifest)
    swapped["swatches"][16]["name"] = "Schwefel"
    assert validate(swapped, lock), "Accidental reassignment must be rejected"
    removed = copy.deepcopy(manifest)
    removed["swatches"].pop()
    assert validate(removed, lock), "Removal of established identity must be rejected"
    print(f"OK: {len(manifest['swatches'])} stable IDs; add/reassignment/removal tests passed")


if __name__ == "__main__":
    main()
