#!/usr/bin/env bash
cd ../$(dirname $(realpath $0))

ARDUINO_SKETCHBOOK="${1:-$HOME/sketchbook}"

if [[ ! -d "$ARDUINO_SKETCHBOOK" ]]; then
    echo "Cannot find arduino sketchbook, specify it as the arg to the cli"
    exit 1
fi

enumerate_folders_in_dir() {
    local top_level_dir="$1"; shift

    find "$top_level_dir" -mindepth 1 -maxdepth 1 -type d
}

for sketch in $(enumerate_folders_in_dir sketches); do
    target="$ARDUINO_SKETCHBOOK/$(basename $sketch)"
    if [[ ! -d "$target" ]]; then
        cp -r "$sketch" "$target"
    else
        echo "$target already exists, not creating"
    fi
done

if [[ ! -d "$ARDUINO_SKETCHBOOK/libraries" ]]; then
    echo "Arduino libraries folder does not exist, creating..."
    mkdir "$ARDUINO_SKETCHBOOK/libraries"
fi

for library in $(enumerate_folders_in_dir libraries); do
    target="$ARDUINO_SKETCHBOOK/libraries/$(basename $library)"
    if [[ ! -d "$target" ]]; then
        cp -r "$library/" "$target"
    else
        echo "$target already exists, not creating"
    fi
done
