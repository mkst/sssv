# SSSV Level Viewer

Browser viewer for level data unpacked by `tools/svle`.

It renders the level geometry, terrain payloads, object and animal markers,
object models, dynamic billboard sprites, paths, links, water, camera regions,
cell-lighting cells, collision cells, and assorted level-config metadata.

## Export

Run exporter commands inside the `sssv` container when it is available.

Export one level:

```sh
python3 tools/svle/level_viewer/export_level_view.py \
  levels/SMASHING_START.json \
  levels/SMASHING_START.view.json
```

Export every known level:

```sh
bash tools/svle/export_level_views.sh
```

The exporter reads `levels/<LEVEL>.json` and sibling level payloads such as
`levels/<LEVEL>.10.bin`, then writes browser-friendly `*.view.json` files.
Generated view JSON and texture outputs are ignored by git.

For object models, also generate the object-viewer data:

```sh
python3 tools/svle/object_viewer/export_object_view.py \
  --output tools/svle/object_viewer/objects.view.json
```

The level viewer loads `/tools/svle/object_viewer/objects.view.json` when object
models are enabled. Without that file, the level still loads, but objects fall
back to simple markers.

## Open

Serve the repository root, then open `/tools/svle/level_viewer/viewer/`:

```sh
python3 -m http.server 8000
```

The page loads `/levels/SMASHING_START.view.json` by default and has a level
dropdown for the generated `levels/*.view.json` files. It uses Three.js from a
CDN, so a fully offline setup would need a vendored/local Three.js copy.

## Controls

- Left mouse drag looks around.
- `W` / `S` move forward and backward.
- `A` / `D` strafe.
- Arrow keys turn and pitch.
- Hold `Shift` to move faster.

The panel toggles SVLE-backed layers, object model rendering, labels, textured
terrain, texture-ID debug coloring, fog, wireframe mode, terrain color mode,
terrain opacity, path snapping, and the in-game long-axis orientation.

Hovering object, animal, and camera-region markers shows decoded metadata.

## Texture Notes

The exporter emits texture metadata into each `*.view.json` and writes derived
PNG previews under `levels/textures/`.

Terrain texture IDs mirror the runtime `D_800BA760` texture arena:

```text
0..19    biome RGBA16 mipmap bank
20..31   level-specific RGBA16 mipmap bank
32..39   biome IA16 mipmap bank
40..     per-level object RGBA16 textures
```

Only the 32x32 top mip is exported for mipmap banks. The smaller mips and
14-byte trailer remain in the source `.mipmap` files but are not represented in
the browser view. The exporter applies the odd-row word swap used by the image
conversion flow before writing browser PNGs.

Per-level object textures are read from `assets/img/levels/<LEVEL>/*.rgba16.png`.
Known alias levels reuse another level's texture folder, for example
`SECRET_LEVEL` uses `SMASHING_START`, `CREDITS` uses
`BIG_CELEBRATION_PARADE`, and `EMPTY_LEVEL_2` uses `HAVE_A_NICE_DAY`.

Dynamic billboard sprites use the `.regular` banks extracted from RNC assets:
categories `0..7` use the biome regular bank, and categories `8..11` use the
level regular bank. The exporter writes combined RGBA16 + I4 PNG previews under
`levels/textures/billboard/`.

## Current Limits

- Rendering is a browser approximation of the runtime pipeline.
- Object model display-list parsing is incomplete, so some models may be
  missing pieces or use fallback textures.
- Dynamic billboard placement and depth behavior are approximate.
- Terrain lighting is currently rendered unlit in Three.js so exported normals
  do not darken the level.
