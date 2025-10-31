#define SOL_ALL_SAFETIES_ON 1

#include <sol/sol.hpp> 
#include <string_view>
#include "main_lua.h"

void setup()
{
    sol::state lua;
    lua.open_libraries(sol::lib::base);    
	lua.script(std::string_view(reinterpret_cast<const char*>(main_lua), main_lua_len));

    sol::function add = lua["Add"];
    int result = add(5, 3);
}

void loop()
{
}