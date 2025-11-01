#define SOL_NO_THREAD_LOCAL 1
#define SOL_ALL_SAFETIES_ON 1

#include <sol/sol.hpp>
#include <string_view>
#include "main_lua.h"
#include <Adafruit_NeoPixel.h>

sol::state lua;
sol::function add;

Adafruit_NeoPixel pixels(1, PIN_NEOPIXEL, NEO_GRB + NEO_KHZ800);

void setup()
{
    lua.open_libraries(sol::lib::base);
    lua.script(std::string_view(reinterpret_cast<const char *>(main_lua), main_lua_len));
    add = lua["Add"];

    pixels.begin();
}

void loop()
{
    pixels.setPixelColor(0, pixels.Color(0, 255, 0));
    pixels.show();
    delay(add(200, 0));

    pixels.setPixelColor(0, pixels.Color(0, 0, 0));
    pixels.show();
    delay(add(200, 0));
}