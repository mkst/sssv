import subprocess

from pathlib import Path
from typing import Optional

from segtypes.n64.segment import N64Segment
from util import options
from util import log

class N64SegRnc(N64Segment):
    def __init__(self, segment, rom_start, rom_end):
        super().__init__(segment, rom_start, rom_end)
        if type(segment) is dict:
            raise Exception("Dict not yet supported!")

    def out_path(self) -> Optional[Path]:
        return options.get_asset_path() / self.dir / f"{self.name}"

    def split(self, rom_bytes):
        path = self.out_path()
        path.parent.mkdir(parents=True, exist_ok=True)
        # create path to temporary file
        tmp_path = path.parent / (path.name + ".tmp")
        # write out RNC file
        with open(tmp_path, "wb") as f:
            f.write(rom_bytes[self.rom_start : self.rom_end])
        # build path to rnc64 binary
        rnc64 = options.get_base_path() / "tools" / "rnc_propack_source" / "rnc64"
        # run rnc64
        args = [rnc64, "u", tmp_path, path]
        res = subprocess.run(args, capture_output=True, check=True)
        # remove temporary file
        tmp_path.unlink()
