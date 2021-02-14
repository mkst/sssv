# Space Station Silicon Valley N64

![build](https://github.com/mkst/sssv/workflows/build/badge.svg)
![progress](https://img.shields.io/badge/dynamic/json?url=https%3A//sssv.deco.mp/latest.json&color=critical&label=progress&query=$.progress[?(@.version=='us')].sections[?(@.section=='all')].percent&suffix=%&link=https%3A//sssv.deco.mp&logo=github&logoColor=959da5&labelColor=353c43)

A WIP decompilation of Space Station Silicon Valley (SSSV) for N64.
Checkout the [wiki](https://github.com/mkst/sssv/wiki) for more information.

**Note:** To use this repository, you must already have a copy of the game.

# Building

The assumption is that you will be using `Ubuntu 20.04`, either natively, via [WSL2](https://docs.microsoft.com/en-us/windows/wsl/install-win10), or via [Docker](https://docs.docker.com/get-docker/).
Please check the [Dockerfile](Dockerfile) for the necessary prerequisites.

## Build steps

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

# Versions

There are 5 known versions of the ROM:

| Country Code               | CRC1       | CRC2       | ROM SHA1                                   | Notes           | Version |
|:---------------------------|:----------:|:----------:|:------------------------------------------:|:----------------|:-------:|
| E - North America          | `BFE23884` | `EF48EAAF` | `e5e09205aa743a9e5043a42df72adc379c746b0b` | US 1.0          | `1.37`  |
| J - Japanese               | `BFE23884` | `EF48EAAF` | `7320f08474c011fc7781093bf1a6818c37ce51e2` | JP (Unreleased) | `1.37`  |
| E - North America          | `FC70E272` | `08FFE7AA` | `c968bba6a90db9ecbd957e910684a80726b0497d` | US 1.1          | `1.37`  |
| P - European (basic spec.) | `FC70E272` | `08FFE7AA` | `23710541bb3394072740b0f0236a7cb1a7d41531` | EU              | `1.37`  |
| ???                        | ???        | ???        | ???                                        | [NES World](http://www.nesworld.com/prototype-details.php?system=n64&data=124) | `1.26B` |

Only US and EU versions were released. If you are in possession of the Prototype ROM, let me know - `mkst#4741`.

## Building EU Version

Place `baserom.eu.z64` in the root of the repository, and suffix each `make` command with `VERSION=eu`.

# ROM Info

## Layout

The layout of the ROM is work-in-progress. Three sections of code have been identified along with a mix of compressed and non-compressed data.

## Compression

Uses [RNC](https://segaretro.org/Rob_Northen_compression) for a number of assets.

Compression is partially matching; 250/263 files match after compression.

A handful of files are compressed twice.

## Obfuscation

There appears to be a level of obfuscation going on in the ROM. For example, the F3DEX microcode is not obvious within the ROM, but it is present in RAM.

# Repo layout

```
asm/             ; assembly files split by splat (not checked in)
bin/             ; binary files split by splat (not checked in)
build/           ; build folder (not checked in)
include/
  2.0I/          ; libultra 2.0I headers
src/
  core/          ; core code
  lib/libultra/  ; libultra code
  sssv/          ; game code
tools/
  ido5.3_recomp/ ; static recompilation of IDO 5.3 compiler
```

# Tools

 - [asm-processor](https://github.com/simonlindholm/asm-processor); allows `GLOBAL_ASM` pragma - replacing assembly inside C files
 - [asm-differ](https://github.com/simonlindholm/asm-differ); rapidly diff between source/target assembly
 - [decomp-permuter](https://github.com/simonlindholm/decomp-permuter); tweaks code, rebuilds, scores; helpful for weird regalloc issues
 - [ido-static-recomp](https://github.com/Emill/ido-static-recomp); no need to use qemu-irix anymore!
 - [mips2c](https://github.com/matt-kempster/mips_to_c.git); assembly to C code translator
 - [rnc_propack_source](https://github.com/lab313ru/rnc_propack_source); open-source compressor/decompressor for RNC file format
 - [splat](https://github.com/ethteck/splat); successor to n64split

# Useful Links
 - [SSSV at TCRF](https://tcrf.net/Space_Station_Silicon_Valley_(Nintendo_64))
 - [SSSV at romhacking.net](http://datacrystal.romhacking.net/wiki/Space_Station_Silicon_Valley_(Nintendo_64))
 - [Music video based on SSSV Prototype build](https://www.youtube.com/watch?v=IAJ4OT6-5GU)
 - [ScriptHawk lua for SSSV](https://github.com/Isotarge/ScriptHawk/blob/master/games/sssv.lua)
 - [EverDrive Forum thread](https://krikzz.com/forum/index.php?topic=6946.0)
