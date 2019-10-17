#!/bin/bash
export LD_LIBRARY_PATH=../../lib/release
export QT_QPA_PLATFORM=wayland
export QT_QPA_FONTDIR=/svp/share/fonts
export QT_WAYLAND_SHELL_INTEGRATION=ivi-shell
export QT_IVI_SURFACE_ID=30000
./client
