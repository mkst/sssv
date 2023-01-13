#!/bin/env bash

BASE=$(readlink -f $(dirname "${BASH_SOURCE[0]}"))
# echo "BASE IS ${BASE}"

source ${BASE}/levels.sh

OUTDIR=${BASE}/../../levels/vrml

mkdir -p ${OUTDIR}

for level in ${LEVELS[@]}; do
  echo "json2wrl: ${level}"
  python3 ${BASE}/other/vrml.py "${BASE}/../../levels/${level}.json" ${OUTDIR}/${level}.wrl
done
