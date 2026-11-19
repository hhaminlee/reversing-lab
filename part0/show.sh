#!/usr/bin/env bash
# 사용법: ./show.sh 파일.c 함수이름 [-O0|-O2]
# C 파일을 컴파일하고 지정한 함수의 어셈블리만 보여줌
set -euo pipefail
if [ $# -lt 2 ]; then
  echo "사용법: ./show.sh 파일.c 함수이름 [-O0|-O2]"
  echo "예시:   ./show.sh 03_if.c check"
  exit 1
fi
src="$1"; fn="$2"; opt="${3:--O0}"
cd "$(dirname "$0")"
mkdir -p build
out="build/$(basename "${src%.c}")${opt}"
# 교재와 같은 결과가 나오도록 읽기에 방해되는 보안 명령(endbr64)과 부가 정보는 끔
gcc "$opt" -fcf-protection=none -fno-asynchronous-unwind-tables -o "$out" "$src"
echo "== $src → $out ($opt) / 함수: $fn =="
objdump -d -M intel --no-show-raw-insn --disassemble="$fn" "$out" | sed -n '/^[0-9a-f]* </,/^$/p'
