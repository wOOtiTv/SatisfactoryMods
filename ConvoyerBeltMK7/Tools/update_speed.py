import unreal

root = "/ConveyorBeltMk7"
unreal.AssetRegistryHelpers.get_asset_registry().scan_paths_synchronous([root], True)
for kind in ("ConveyorBelt", "ConveyorLift"):
    for prefix in ("Build", "Desc"):
        path = f"{root}/{prefix}_{kind}Mk7"
        cls = unreal.EditorAssetLibrary.load_blueprint_class(path)
        obj = unreal.get_default_object(cls)
        obj.set_editor_property("m_description", unreal.Text("Ausgelegt auf 3.000 Ressourcen pro Minute."))
        if prefix == "Build":
            # Vanilla Mk.6 uses 2400 internal units for 1200 items/min.
            obj.set_editor_property("m_speed", 6000.0)
            assert obj.get_editor_property("m_speed") == 6000.0
        assert unreal.EditorAssetLibrary.save_asset(path, only_if_is_dirty=False), path
