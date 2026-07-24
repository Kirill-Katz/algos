#!/usr/bin/env bash

set -e

if [ $# -ne 1 ]; then
    echo "Usage: ./run.sh file.cpp"
    exit 1
fi

src="$1"

if [ ! -f "$src" ]; then
    echo "File not found: $src"
    exit 1
fi

mkdir -p bin

name=$(basename "$src" .cpp)
out="bin/$name"

g++-16 -std=gnu++20 -O2 -Wall -Wextra "$src" -o "$out"

"$out"

