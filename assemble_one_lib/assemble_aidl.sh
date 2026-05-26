#!/usr/bin/env bash
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

SRC_BIN="${SCRIPT_DIR}/build/single_lib_demo"
SRC_LIB="${SCRIPT_DIR}/build/AidlHAL/libHDMICecHal.so"
OUT_DIR="${SCRIPT_DIR}/out"

if [[ ! -f "${SRC_BIN}" ]]; then
    echo "Missing binary: ${SRC_BIN}" >&2
    exit 1
fi

if [[ ! -f "${SRC_LIB}" ]]; then
    echo "Missing library: ${SRC_LIB}" >&2
    exit 1
fi

rm -rf "${OUT_DIR}"
mkdir -p "${OUT_DIR}"

cp "${SRC_BIN}" "${OUT_DIR}/single_lib_demo"
cp "${SRC_LIB}" "${OUT_DIR}/libHDMICecHal.so"

echo "Assembled aidl artifacts in: ${OUT_DIR}"
