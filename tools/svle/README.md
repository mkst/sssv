# Silicon Valley Level Editor

Very work-in-progress scripts to unpack the SSSV Level Data into human-readable format.

Not all level-data segments are understood, these are simply extracted as '.bin' files rather than being part of the `json` output.

## level-2-json (l2j)

```sh
# extract SMASHING_START to /tmp
python3 l2j.py ../../assets/levels/SMASHING_START.bin /tmp
```

## json-2-level (j2l)

```sh
# pack SMASHING_START files & json to /tmp/SMASHING_START.bin
python3 j2l.py /tmp/SMASHING_START.json /tmp/SMASHING_START.bin
```
