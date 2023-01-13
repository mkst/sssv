#!/bin/env bash

BASE=$(readlink -f $(dirname "${BASH_SOURCE[0]}"))
# echo "BASE IS ${BASE}"

source ${BASE}/levels.sh

mkdir -p ${BASE}/../../levels/packed

for level in ${LEVELS[@]}; do
  echo "json2level: ${level}"
  python3 ${BASE}/j2l.py "${BASE}/../../levels/${level}.json" ${BASE}/../../levels/packed
done
