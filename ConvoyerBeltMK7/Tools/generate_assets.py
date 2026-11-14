"""Run from the CSS Unreal Editor with Python enabled to generate Mk.7 assets."""

import unreal

PLUGIN = "/ConveyorBeltMk7"
FACTORY = "/Game/FactoryGame"
BELT_FOLDER = f"{FACTORY}/Buildable/Factory/ConveyorBeltMk6"
TARGET_RATE = 3200
VANILLA_RATE = 1200

ASSET_SPECS = (
    (f"{BELT_FOLDER}/Build_ConveyorBeltMk6", f"{PLUGIN}/Build_ConveyorBeltMk7"),
    (f"{BELT_FOLDER}/Desc_ConveyorBeltMk6", f"{PLUGIN}/Desc_ConveyorBeltMk7"),
    (f"{FACTORY}/Recipes/Buildings/Recipe_ConveyorBeltMk6", f"{PLUGIN}/Recipe_ConveyorBeltMk7"),
)


def blueprint_class(path):
    generated_class = unreal.EditorAssetLibrary.load_blueprint_class(path)
    if generated_class is None:
        raise RuntimeError(f"Cannot load Blueprint class: {path}")
    return generated_class


def main():
    library = unreal.EditorAssetLibrary
    for source, destination in ASSET_SPECS:
        blueprint_class(source)
        if library.does_asset_exist(destination):
            raise RuntimeError(f"Asset already exists: {destination}")

    belt_path, descriptor_path, recipe_path = [destination for _, destination in ASSET_SPECS]
    reference = unreal.get_default_object(blueprint_class(ASSET_SPECS[0][0]))
    reference_speed = reference.get_editor_property("m_speed")
    if reference_speed <= 0:
        raise RuntimeError("Vanilla Mk.6 reference speed must be positive")

    for source, destination in ASSET_SPECS:
        if library.duplicate_asset(source, destination) is None:
            raise RuntimeError(f"Duplication failed: {source}")

    belt_class = blueprint_class(belt_path)
    descriptor_class = blueprint_class(descriptor_path)
    belt = unreal.get_default_object(belt_class)
    descriptor = unreal.get_default_object(descriptor_class)
    blueprint_class(recipe_path)

    belt.set_editor_property("m_speed", reference_speed * TARGET_RATE / VANILLA_RATE)
    descriptor.set_editor_property("m_buildable_class", belt_class)
    display_name = unreal.Text("Förderband Mk.7")
    belt.set_editor_property("m_display_name", display_name)
    descriptor.set_editor_property("m_display_name", display_name)
    for _, destination in ASSET_SPECS:
        if not library.save_asset(destination, only_if_is_dirty=False):
            raise RuntimeError(f"Saving failed: {destination}")
    unreal.log(f"Mk.7 template assets saved. Link the recipe manually. Nominal target: {TARGET_RATE} items/min.")


if __name__ == "__main__":
    main()
