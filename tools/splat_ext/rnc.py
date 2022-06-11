import subprocess

from pathlib import Path
from typing import Optional

from segtypes.n64.segment import N64Segment
from segtypes.n64.rgba16 import N64SegRgba16
from segtypes.n64.i4 import N64SegI4

from util import options, log


class N64SegRnc(N64Segment):
    def __init__(self, rom_start, rom_end, type, name, vram_start, extract,
                 given_subalign, exclusive_ram_id, given_dir, symbol_name_format, symbol_name_format_no_rom, args=[], yaml={}):
        super().__init__(rom_start, rom_end, type, name, vram_start, extract,
                         given_subalign, exclusive_ram_id, given_dir, symbol_name_format, symbol_name_format_no_rom, args, yaml)
        if len(self.args) > 0:
            self.subtype = self.args[0]
            if self.subtype in ("i4", "rgba16"):
                if len(self.args) < 3:
                    log.error(f"Error: {self.name} is missing 'width' and 'height' parameters")
                self.width = self.args[1]
                self.height = self.args[2]
                # append type to filename
                self.name += f".{self.subtype}"
        else:
            self.subtype = None
        # append .rnc
        self.name += ".rnc"

    def out_path(self) -> Optional[Path]:
        return options.get_asset_path() / self.dir / f"{self.name}"

    def split(self, rom_bytes):
        # stage 1: decompression
        path = self.out_path()
        path.parent.mkdir(parents=True, exist_ok=True)
        # create path to temporary file
        tmp_path = path.parent / (path.name + ".tmp")
        # write out RNC file
        with open(tmp_path, "wb") as f:
            f.write(rom_bytes[self.rom_start:self.rom_end])
        # build path to rnc64 binary
        rnc64 = options.get_base_path() / "tools" / "rnc_propack_source" / "rnc64"
        # run rnc64
        args = [rnc64, "u", tmp_path, path]
        subprocess.run(args, capture_output=True, check=True)
        # remove temporary file
        tmp_path.unlink()
        # stage 2: decoding
        if self.subtype is not None:
            with open(path, "rb") as infile:
                data = infile.read()
            if self.subtype == "rgba16":
                args = [None, None, None, self.width, self.height]
                seg = N64SegRgba16(0, len(data), self.subtype, self.name, self.vram_start,
                                   self.extract, self.given_subalign, self.get_exclusive_ram_id(),
                                   self.given_dir, self.symbol_name_format, self.symbol_name_format_no_rom, [], args)
            elif self.subtype == "i4":
                args = [None, None, None, self.width, self.height]
                seg = N64SegI4(0, len(data), self.subtype, self.name, self.vram_start,
                               self.extract, self.given_subalign, self.get_exclusive_ram_id(),
                               self.given_dir, self.symbol_name_format, self.symbol_name_format_no_rom, [], args)
            else:
                log.error(f"Error: Unsupported subtype: {self.subtype}")
            seg.split(data)
            path.unlink()
