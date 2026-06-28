import sys
from pathlib import Path
from typing import Optional

from splat.segtypes.common.segment import CommonSegment
from splat.segtypes.n64.i4 import N64SegI4
from splat.segtypes.n64.rgba16 import N64SegRgba16
from splat.util import log, options

sys.path.append(str(options.opts.base_path / "tools"))

from rncu import RncUnpackerMethod1


IMAGE_FORMAT_LOOKUP = {
    "rgba16": N64SegRgba16,
    "i4": N64SegI4,
}
RAW_BANK_SUBTYPES = {"mipmap", "regular"}


def decompress_rnc_bytes(data):
    return bytes(RncUnpackerMethod1(data).unpack())


class N64SegRnc(CommonSegment):
    def __init__(self, rom_start, rom_end, type, name, vram_start, args, yaml, bss_size=None):
        super().__init__(rom_start, rom_end, type, name, vram_start, args=args, yaml=yaml, bss_size=bss_size)

        if len(self.args) > 0:
            self.subtype = self.args[0]
            if self.subtype in IMAGE_FORMAT_LOOKUP:
                if len(self.args) < 3:
                    log.error(f"Error: {self.name} is missing 'width' and 'height' parameters")
                self.width = self.args[1]
                self.height = self.args[2]
                self.name += f".{self.subtype}.rnc"
            elif self.subtype in ("mipmap", "regular"):
                self.name += f".{self.subtype}"
            else:
                log.error(f"Error: 'rnc' segment only supports 'i4', 'rgba16', 'mipmap', and 'regular' subtypes in list form")
        elif isinstance(yaml, dict):
            self.subtype = yaml.get("subtype")
            if self.subtype in ("mipmap", "regular"):
                self.name += f".{self.subtype}"
            else:
                log.error(f"Error: 'rnc' segment only supports 'mipmap' and 'regular' subtypes in dict form")
        else:
            self.subtype = None
            self.name += ".rnc"

    def out_path(self) -> Optional[Path]:
        return options.opts.asset_path / self.dir / f"{self.name}"

    def get_linker_entries(self):
        from splat.segtypes.linker_entry import LinkerEntry

        if self.subtype in RAW_BANK_SUBTYPES:
            path = self.out_path()
            return [
                LinkerEntry(
                    self,
                    [path],
                    path.with_suffix(path.suffix + ".rnc"),
                    self.get_linker_section_order(),
                    self.get_linker_section_linksection(),
                    self.is_noload(),
                )
            ]

        return super().get_linker_entries()

    def split(self, rom_bytes):
        path = self.out_path()
        path.parent.mkdir(parents=True, exist_ok=True)
        unpacked = decompress_rnc_bytes(rom_bytes[self.rom_start:self.rom_end])
        path.write_bytes(unpacked)

        if self.subtype in IMAGE_FORMAT_LOOKUP:
            path.unlink()
            yaml = [None, None, None, self.width, self.height]
            seg = IMAGE_FORMAT_LOOKUP[self.subtype](
                0, len(unpacked), self.subtype, self.name, self.vram_start, [], yaml
            )
            seg.image_type_in_extension = False
            seg.split(unpacked)
        elif self.subtype in RAW_BANK_SUBTYPES:
            # Raw texture banks are left decompressed. Use tools/mipmap_bank.py
            # or tools/regular_bank.py to unpack/pack editable PNGs.
            pass
        elif self.subtype is not None:
            log.error(f"Error: Unsupported subtype: {self.subtype}")
