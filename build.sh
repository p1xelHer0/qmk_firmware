#!/usr/bin/env bash
set -eu

RED="\e[31m"
END="\e[0m"

kb_plain60="evyd13/plain60"

for arg in "$@"; do declare $arg='1'; done
if [ -v db ];    then echo    "[build]: generating compile_commands.json"; fi
if [ -v flash ]; then echo -e "$RED[build]: flashing after compilation, put keyboard in DFU mode$END"; fi

if [ -v plain60 ]; then kb=$kb_plain60; fi
if [ ! -v kb ]
then
  echo -e "$RED[error]: no keyboard selected, specify one: \`./build.sh plain60\`$END"
  exit 1
fi

qmk_cmd="qmk compile -kb $kb -km p1xelHer0"
flash_cmd="qmk flash -kb $kb -km p1xelHer0"

if [ -v db ];   then compile_cmd="$qmk_cmd --compiledb"; fi
if [ ! -v db ]; then compile_cmd="$qmk_cmd"; fi

if [ -v kb ];    then echo "[build]: building \`$compile_cmd\`" && $compile_cmd; fi
if [ -v flash ]; then echo "[build]: flashing \`$flash_cmd\`"   && $flash_cmd; fi
