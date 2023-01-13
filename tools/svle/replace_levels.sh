#!/bin/env bash

BASE=$(readlink -f $(dirname "${BASH_SOURCE[0]}"))

source ${BASE}/levels.sh

TARGET_DIR=$(readlink -f ${BASE}/../../assets/levels)

for level in ${LEVELS[@]}; do
  repacked_level=$(readlink -f ${BASE}/../../levels/packed/${level}.bin)
  if [[ -f ${repacked_level} ]]; then
    cp -v ${repacked_level} ${TARGET_DIR}
  fi
done
