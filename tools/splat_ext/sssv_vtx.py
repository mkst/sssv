"""
N64 Vtx struct splitter

Dumps out Vtx as a .inc.c file. Use the label argument to create a standalone file.

Usage:
    - [rom_offset, 'vtx', filename, label]

Additional arguments:
 * label;       name of variable, defaults to 'D_' + memory address.
"""

import struct
import sys
from typing import Optional
from pathlib import Path

# splat modules
from util import options
from segtypes.common.codesubsegment import CommonSegCodeSubsegment


class N64SegSssv_vtx(CommonSegCodeSubsegment):
    def __init__(self, rom_start, rom_end, type, name, vram_start, extract,
                 given_subalign, exclusive_ram_id, given_dir, symbol_name_format, symbol_name_format_no_rom, args = [], yaml = {}):
        super().__init__(rom_start, rom_end, type, name, vram_start, extract,
                         given_subalign, exclusive_ram_id, given_dir, symbol_name_format, symbol_name_format_no_rom, args, yaml)
        self.file_text = None

        if len(self.args) > 0:
            self.label = self.args[0]
            self.standalone = True
        else:
            self.label = None
            self.standalone = False

    def get_linker_section(self) -> str:
        return '.data'

    def get_linker_entries(self) -> 'List[LinkerEntry]':
        from segtypes.linker_entry import LinkerEntry

        path = self.out_path()

        if path and self.standalone:
            return [LinkerEntry(self, [path], path, self.get_linker_section())]
        else:
            return []

    def out_path(self) -> Optional[Path]:
        return options.get_src_path() / self.dir / f'{self.name}.inc.c'

    def scan(self, rom_bytes: bytes):
        self.file_text = self.disassemble_data(rom_bytes)

    def get_label(self):
        return self.label

    def disassemble_data(self, rom_bytes):
        vertex_data = rom_bytes[self.rom_start:self.rom_end]
        segment_length = len(vertex_data)
        if (segment_length) % 16 != 0:
            print(f'Error: Vtx segment {self.name} length ({segment_length}) is not a multiple of 16!')
            sys.exit(1)

        lines = []
        if self.standalone:
            preamble = options.get('generated_c_preamble', '#include "common.h"')
            lines.append(preamble)

        vertex_count = segment_length // 16
        if self.standalone:
            lines.append(f'Vtx {self.label}[{vertex_count}] = {{')

        for vtx in struct.iter_unpack('>hhhHhhBBBB', vertex_data):
            x, y, z, flg, t, c, r, g, b, a = vtx
            indent = '    ' if self.standalone else ''
            vtx_string = f'{indent}{{{{{{ {x:5}, {y:5}, {z:5} }}, {flg}, {{ {t:5}, {c:5} }}, {{ {r:3}, {g:3}, {b:3}, {a:3} }}}}}},'
            if flg != 0:
                self.warn(f'Non-zero flag found in vertex data {self.name}!')
            lines.append(vtx_string)

        if self.standalone:
            lines.append('};')

        # enforce newline at end of file
        lines.append('')
        return '\n'.join(lines)

    def split(self, rom_bytes: bytes):
        if self.file_text:
            if path := self.out_path():
                path.parent.mkdir(parents=True, exist_ok=True)
                if not path.exists():
                    with open(path, 'w', newline='\n') as f:
                        f.write(self.file_text)
