#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
#include <raylib.h>

int momentum_time_getDelta(lua_State *L) {
    lua_pushnumber(L, GetFrameTime());

    return 1;
}

const luaL_Reg momentum_time_reg[] = {
    {"getDelta", momentum_time_getDelta},
    {NULL, NULL}
};

int luaopen_momentum_time(lua_State *L) {
    luaL_newlib(L, momentum_time_reg);

    return 1;
}
