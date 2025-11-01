# Arduino CLI installieren
curl -fsSL https://raw.githubusercontent.com/arduino/arduino-cli/master/install.sh | sh

# Core-Index aktualisieren
./bin/arduino-cli core update-index --additional-urls https://espressif.github.io/arduino-esp32/package_esp32_index.json

# ESP32 Core installieren
./bin/arduino-cli core search --all
./bin/arduino-cli core install esp32:esp32@3.3.2

# Bibliotheken installieren
./bin/arduino-cli lib install "Adafruit NeoPixel"

# Compile Arduino Application
 ./bin/arduino-cli compile --output-dir . --fqbn esp32:esp32:adafruit_feather_esp32s3 --build-property "compiler.cpp.extra_flags=-IExample/include -IExample/src -std=c++17" Example

# Flash to MCU
nix-shell -p esptool
esptool.py --chip esp32s3 --port /dev/ttyACM0 --baud 921600 --before default_reset --after hard_reset write_flash 0x0 Example.ino.merged.bin

# Convert Lua-script to C-header
xxd -i main.lua > main_lua.h

# Compile executable for host
g++ main.cpp src/lapi.c src/lcode.c src/lctype.c src/ldebug.c src/ldo.c src/ldump.c src/lfunc.c src/lgc.c src/llex.c src/lmem.c src/lobject.c src/lopcodes.c src/lparser.c src/lstate.c src/lstring.c src/ltable.c src/ltm.c src/lundump.c src/lvm.c src/lzio.c src/lauxlib.c src/lbaselib.c src/lcorolib.c src/ldblib.c src/liolib.c src/lmathlib.c src/loadlib.c src/loslib.c src/lstrlib.c src/ltablib.c src/lutf8lib.c src/linit.c -Iinclude -Isrc -std=c++17



