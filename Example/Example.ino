#define SOL_NO_THREAD_LOCAL 1
#define SOL_ALL_SAFETIES_ON 1

#include <sol/sol.hpp> 
#include <string_view>
#include "main_lua.h"
#include <Adafruit_NeoPixel.h>

sol::state lua;
sol::function add;

Adafruit_NeoPixel pixels(1, PIN_NEOPIXEL);


void setup()
{
    lua.open_libraries(sol::lib::base);    
    lua.script(std::string_view(reinterpret_cast<const char*>(main_lua), main_lua_len));
    add = lua["Add"];

    pixels.begin();
}

void loop()
{
    int result = add(5, 3);
}