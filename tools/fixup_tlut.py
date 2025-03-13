"""
Horrible hack to create a filename.ci4.png file based on filename/TLUT.ci4.png
"""
import glob
import shutil

from pathlib import Path

paths = [Path(x) for x in glob.glob("./assets/**/*/*TLUT*.ci4.png")]

for path in paths:
    new_path = path.parent.with_suffix(".ci4.png")
    if not new_path.is_file():
        # print(f"Copying {path} to {new_path}...")
        shutil.copy(path, new_path)
