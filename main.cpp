#define SOL_USING_CXX_LUA 1
#define SOL_ALL_SAFETIES_ON 1

#include <sol/sol.hpp> 
#include <iostream>
#include <string_view>
#include "main_lua.h"

int main() {
    sol::state lua;
    lua.open_libraries(sol::lib::base);    
	lua.script(std::string_view(reinterpret_cast<const char*>(main_lua), main_lua_len));

    sol::function add = lua["Add"];
    int result = add(5, 3);
    
    std::cout << "Ergebnis: " << result << std::endl;
	
    return 0;
}