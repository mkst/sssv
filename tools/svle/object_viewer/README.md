# SSSV Object Viewer

Early browser viewer for object display lists exported from `src.us/data/objects_7B9BD0.c`.

## Export

Run exporter commands inside the `sssv` container:

```sh
docker exec sssv python3 tools/svle/object_viewer/export_object_view.py \
  --output tools/svle/object_viewer/objects.view.json
```

Export selected objects by repeating `--object` with an object macro or numeric ID:

```sh
docker exec sssv python3 tools/svle/object_viewer/export_object_view.py \
  --object OBJECT_BOULDER \
  --object OBJECT_BUTTON \
  --output tools/svle/object_viewer/objects.view.json
```

The generated `*.view.json` files are ignored by git. Object scope labels are
inferred from the display-list source segment in `sssv.us.yaml`: `segment1` is
global, `*_biome` segments are biome-specific, and `0x05000000` overlay slots
are treated as level/special assets.

## View

Serve the repository root, then open `/tools/svle/object_viewer/viewer/`:

```sh
python3 -m http.server 8000
```

The page loads `/tools/svle/object_viewer/objects.view.json` by default. The viewer
uses Three.js from a CDN, like the SVLE viewer.

## Current Limits

- Geometry export handles vertices, triangles, quadrangles, and primitive color
  overrides.
- Texture commands are not interpreted yet.
- Display-list nesting is not expanded yet, so some objects may be incomplete.
- Animal body-part assembly and animation are planned separately.
