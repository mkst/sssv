#!/bin/env bash

BASE=$(readlink -f $(dirname "${BASH_SOURCE[0]}"))
# echo "BASE IS ${BASE}"

source ${BASE}/levels.sh

mkdir -p ${BASE}/../../levels

for level in ${LEVELS[@]}; do
  echo "level2json: ${level}"
  python3 ${BASE}/l2j.py "${BASE}/../../assets/levels/${level}.bin" ${BASE}/../../levels/
done
