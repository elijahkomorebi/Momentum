#include <lauxlib.h>
#include <lualib.h>
#include <raylib.h>
#include "momentum_lua.h"

int momentum_lua_version(lua_State *L) {
    lua_pushstring(L, LUA_RELEASE);
    
    return 1;
}

int momentum_lua_memory(lua_State *L) {
    lua_pushinteger(L, lua_gc(L, LUA_GCCOUNT, 0) * 1024 + lua_gc(L, LUA_GCCOUNTB, 0));

    return 1;
}

const luaL_Reg momentum_lua_reg[] = {
    {"version", momentum_lua_version},
    {"memory", momentum_lua_memory},
    {NULL, NULL}
};

int luaopen_momentum_lua(lua_State *L) {
    luaL_newlib(L, momentum_lua_reg);

    return 1;
}
