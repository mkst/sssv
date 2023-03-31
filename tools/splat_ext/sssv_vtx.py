from pathlib import Path

from util import options
from segtypes.n64.vtx import N64SegVtx


class N64SegSssv_vtx(N64SegVtx):
    def __init__(self, rom_start, rom_end, type, name, vram_start, args, yaml):
        super().__init__(
            rom_start, rom_end, type, name, vram_start, args=args, yaml=yaml
        )
        self.data_only = True

    def out_path(self) -> Path:
        return options.opts.src_path / self.dir / f"{self.name}.inc.c"

    def scan(self, rom_bytes: bytes):
        if self.out_path().exists():
            # ignore files that have already been split
            return
        self.file_text = self.disassemble_data(rom_bytes)

    def get_linker_entries(self) -> "List[LinkerEntry]":
        return []
