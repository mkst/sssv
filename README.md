# Space Station Silicon Valley N64

![build](https://github.com/mkst/sssv/workflows/build/badge.svg)
![progress](https://img.shields.io/badge/dynamic/json?url=https%3A//sssv.deco.mp/latest.json&color=critical&label=progress&query=$.progress[?(@.version=='us')].sections[?(@.section=='all')].percent&suffix=%&link=https%3A//sssv.deco.mp&logo=github&logoColor=959da5&labelColor=353c43)

A WIP decompilation of Space Station Silicon Valley (SSSV) for N64.
Checkout the [wiki](https://github.com/mkst/sssv/wiki) for more information.

**Note:** To use this repository, you must already own a copy of the game.

# Building

The instructions below assume that you will be using `Ubuntu 20.04`; either natively, via [WSL2](https://docs.microsoft.com/en-us/windows/wsl/install-win10), or via [Docker](https://docs.docker.com/get-docker/).
Please check the [packages.txt](packages.txt) and [requirements.txt](requirements.txt) for the  prerequisite Linux and Python packages respectively.

**Note:** `mips-elf-ld` version `2.34` or older is required, at the time of writing this must be compiled manually (see [Dockerfile](Dockerfile) for the steps).

## Natively

Clone the repository; note the `--recursive` flag to fetch submodules at the same time:

```sh
git clone git@github.com:mkst/sssv.git --recursive
```

Navigate into the freshly cloned repo

```sh
cd sssv
```

Place the **US 1.0** SSSV ROM in the root of this repository, name it `baserom.us.z64`, and then run the first `make` command to extract the ROM:

```sh
make extract
```

Now build the ROM:

```sh
make --jobs
```

If you did everything correctly, you'll be greeted with the following:

```sh
build/sssv.us.z64: OK
```

## Docker

Clone this repository, place the `baserom.us.z64` at its root, and then run the Docker image via:

```sh
docker run --rm -ti -v $(pwd):/sssv ghcr.io/mkst/sssv:latest
```

From here you can run the `make extract` and `make --jobs` commands.

## Building `EU` Version

Place `baserom.eu.z64` in the root of the repository, and suffix each `make` command with `VERSION=eu`. Note that whilst this will build the EU ROM, minimal effort has been made to decompile this version.

## Building `NON_MATCHING` Version

A number of functions within the ROM have been decompiled to a state where they are functionally equivalent, but not byte-perfect. Progress is approximately 1% ahead of the fully matching build. In order to build/test the non-matching, add `NON_MATCHING=1` to the `make` commands.

# ROM Versions

There are 5 known versions of the ROM:

| Country Code      | CRC1/CRC2           | ROM SHA1                                   | Notes           | Version |
|:------------------|:-------------------:|:------------------------------------------:|:----------------|:-------:|
| E - North America | `BFE23884/EF48EAAF` | `e5e09205aa743a9e5043a42df72adc379c746b0b` | US 1.0          | `1.37`  |
| J - Japanese      | `BFE23884/EF48EAAF` | `7320f08474c011fc7781093bf1a6818c37ce51e2` | JP (Unreleased) | `1.37`  |
| E - North America | `FC70E272/08FFE7AA` | `c968bba6a90db9ecbd957e910684a80726b0497d` | US 1.1          | `1.37`  |
| P - European      | `FC70E272/08FFE7AA` | `23710541bb3394072740b0f0236a7cb1a7d41531` | EU              | `1.37`  |
| ???               | ???                 | ???                                        | [NES World](http://www.nesworld.com/prototype-details.php?system=n64&data=124) | `1.26B` |

Only US and EU versions were released. If you are in possession of a beta/prototype ROM, please let me know - `mkst#4741`.

# ROM Info

## Layout

The layout of the ROM is work-in-progress. Three sections of code have been identified along with a mix of compressed and non-compressed data.

### Main

This is the code that is loaded when the ROM first starts up, it is responsible for spawning the various game threads, handling controller input, playing sound effects etc. Also includes the `libultra` library code.

### Overlay1

This is the code for the language select, intro cinematics and not much else.

**Note:** In the EU ROM this section is compiled without optimisation!

### Overlay2

Overlay2 contains the core Space Station Silicon Valley game logic.

## Compression

Uses [RNC](https://segaretro.org/Rob_Northen_compression) for a number of assets.

Compression is almost completely matching; 261/263 files match after compression. `rnc_461900` and `rnc_63DC20` are still a problem.

A handful of files are compressed twice; these appear to be the game level data.

In order to decompress the game assets run `make decompress` after you have performed the `make extract` step. This will be done automatically when matching compression has been figured out.

# Repo layout

```
asm/             ; assembly files split by splat (not checked in)
assets/          ; binary files split by splat (not checked in)
build/           ; build folder (not checked in)
include/
  2.0I/          ; libultra 2.0I headers
lib/libultra.a   ; libultra 2.0I static library
src.{us|eu})/
  core/          ; core code
  data/          ; game data e.g. DisplayLists, Vtx + more
  libultra/      ; custom libultra code
  sssv/          ; game code
tools/
  ido5.3_recomp/ ; static recompilation of IDO 5.3 compiler
  splat_ext      ; custom splat extensions
```

# Tools

 - [asm-processor](https://github.com/simonlindholm/asm-processor); allows `GLOBAL_ASM` pragma - replacing assembly inside C files
 - [asm-differ](https://github.com/simonlindholm/asm-differ); rapidly diff between source/target assembly
 - [decomp-permuter](https://github.com/simonlindholm/decomp-permuter); tweaks code, rebuilds, scores; helpful for weird regalloc issues
 - [ido-static-recomp](https://github.com/Emill/ido-static-recomp); no need to use qemu-irix anymore!
 - [mips2c](https://github.com/matt-kempster/mips_to_c); assembly to C code translator
 - [rnc_propack_source](https://github.com/lab313ru/rnc_propack_source); open-source compressor/decompressor for RNC file format
 - [splat](https://github.com/ethteck/splat); successor to n64split

# Useful Links
 - [SSSV at TCRF](https://tcrf.net/Space_Station_Silicon_Valley_(Nintendo_64))
 - [SSSV at romhacking.net](http://datacrystal.romhacking.net/wiki/Space_Station_Silicon_Valley_(Nintendo_64))
 - [Music video based on SSSV Prototype build](https://www.youtube.com/watch?v=IAJ4OT6-5GU)
 - [ScriptHawk lua for SSSV](https://github.com/Isotarge/ScriptHawk/blob/master/games/sssv.lua)
 - [EverDrive Forum thread](https://krikzz.com/forum/index.php?topic=6946.0)
 - [NESWORLD Prototype ROM](http://nesworld.com/prototype-details.php?system=n64&data=124)
 - [Magazine scans of reviews of SSSV](https://www.nintendo64ever.com/Tests-Nintendo-64-Game,321,Space-Station-Silicon-Valley,1.html)
