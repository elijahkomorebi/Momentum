#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
#include <raylib.h>
#include "momentum_window.h"

int momentum_window_close(lua_State *L) {
    CloseWindow();

    return 0;
}

int momentum_window_setTargetFPS(lua_State *L) {
    int targetFPS = luaL_checkinteger(L, 1);

    SetTargetFPS(targetFPS);

    return 0;
}

int momentum_window_getWidth(lua_State *L) {
    lua_pushinteger(L, GetScreenWidth());

    return 1;
}

int momentum_window_getHeight(lua_State *L) {
    lua_pushinteger(L, GetScreenHeight());

    return 1;
}

const luaL_Reg momentum_window_reg[] = {
    {"close", momentum_window_close},
    {"setTargetFPS", momentum_window_setTargetFPS},
    {"getWidth", momentum_window_getWidth},
    {"getHeight", momentum_window_getHeight},
    {NULL, NULL}
};

int luaopen_momentum_window(lua_State *L) {
    luaL_newlib(L, momentum_window_reg);
    
    return 1;
}
