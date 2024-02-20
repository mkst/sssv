from pathlib import Path
from typing import Optional

from src.splat.util import options, log

from src.splat.segtypes.n64.segment import N64Segment
from src.splat.segtypes.n64.rgba16 import N64SegRgba16
from src.splat.segtypes.n64.i4 import N64SegI4


import sys
sys.path.append(str(options.opts.base_path / "tools"))

from rncu import RncUnpackerMethod1


IMAGE_FORMAT_LOOKUP = {
    "rgba16": N64SegRgba16,
    "i4": N64SegI4,
}

def get_mipmap_size(width, height, typ):
    # FIXME
    return 0xab8


class N64SegRnc(N64Segment):
    def __init__(self, rom_start, rom_end, type, name, vram_start, args, yaml):
        super().__init__(rom_start, rom_end, type, name, vram_start, args=args, yaml=yaml),
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
                log.error(f"Error: 'rnc' segment only supports 'i4' and 'rgba16' subtypes in list form")
        elif isinstance(yaml, dict):
            self.subtype = yaml["subtype"]
            if self.subtype == "mipmap":
                log.write("mipmap found")
                self.name += f".{self.subtype}"
                self.subsegments = yaml["subsegments"]
            else:
                log.error(f"Error: 'rnc' segment only supports 'mipmap' subtype in list form")
        else:
            self.subtype = None
        # append .rnc
        self.name += ".rnc"

    def out_path(self) -> Optional[Path]:
        return options.opts.asset_path / self.dir / f"{self.name}"

    def split(self, rom_bytes):
        # stage 1: decompression
        path = self.out_path()
        path.parent.mkdir(parents=True, exist_ok=True)
        rnc_unpacker = RncUnpackerMethod1(rom_bytes[self.rom_start:self.rom_end])
        unpacked = rnc_unpacker.unpack()
        with path.open("wb") as f:
            f.write(unpacked)

        # stage 2: decoding
        if self.subtype is not None:
            if self.subtype == "rgba16":
                yaml = [None, None, None, self.width, self.height]
                seg = N64SegRgba16(0, len(unpacked), self.subtype, self.name, self.vram_start, [], yaml)
                seg.split(unpacked)
            elif self.subtype == "i4":
                yaml = [None, None, None, self.width, self.height]
                seg = N64SegI4(0, len(unpacked), self.subtype, self.name, self.vram_start, [], yaml)
                seg.split(unpacked)
            elif self.subtype == "mipmap":
                offset = 0
                for subsegment in self.subsegments:
                    id, typ, width, height = subsegment
                    expected_len = get_mipmap_size(width, height, typ)
                    yaml = {
                        "width": width,
                        "height": height,
                        "mipmap": True,
                    }

                    name = self.name + f".{id}.{typ}"

                    img_func = IMAGE_FORMAT_LOOKUP.get(typ, None)
                    if img_func is None:
                        log.error(f"Error: Unexpected image format for mipmap: {typ}")

                    seg = img_func(0, expected_len, typ, name, self.vram_start, [], yaml)
                    seg.split(unpacked[offset:offset+expected_len])
                    offset += expected_len
            else:
                log.error(f"Error: Unsupported subtype: {self.subtype}")
