# libultra_rom.a

The `libultra_rom.a` static library was taken from the [IRIX v2.0I](https://ultra64.ca/files/software/nintendo/Nintendo_64_Developers_OS-Library_IRIX_v2.0I/Nintendo_64_Developers_OS-Library_IRIX_v2.0I.iso) CD.

```sh

mkdir -p /tmp/libultra

wget -O /tmp/libultra/libultra.iso https://ultra64.ca/files/software/nintendo/Nintendo_64_Developers_OS-Library_IRIX_v2.0I/Nintendo_64_Developers_OS-Library_IRIX_v2.0I.iso

7z x -O/tmp/libultra /tmp/libultra/libultra.iso

tar xvf /tmp/libultra/os20i.tar -C /tmp/libultra --wildcards dist/ultra*

python3 extract_idb.py /tmp/libultra/dist/ultra.idb \
    --data-file /tmp/libultra/dist/ultra.dev \
    --single-file libultra_rom.a \
    --output-dir /tmp/libultra

mv /tmp/libultra/usr/lib/libultra_rom.a libultra_rom.a
```

Strip symbols to avoid `.symtab local symbol at index 3 (>= sh_info of 2)` error:

```sh
mkdir libultra_rom

mips-linux-gnu-ar x --output libultra_rom libultra_rom.a

for f in libultra_rom/*.o; do mips-linux-gnu-strip --strip-unneeded $f; done

mips-linux-gnu-ar r libultra_rom.a libultra_rom/*.o
```
