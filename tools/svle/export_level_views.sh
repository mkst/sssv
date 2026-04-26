#!/bin/env bash

BASE=$(readlink -f $(dirname "${BASH_SOURCE[0]}"))

source ${BASE}/levels.sh

LEVELS_DIR=${BASE}/../../levels

for level in ${LEVELS[@]}; do
  echo "level2view: ${level}"
  python3 ${BASE}/level_viewer/export_level_view.py "${LEVELS_DIR}/${level}.json" "${LEVELS_DIR}/${level}.view.json"
done
