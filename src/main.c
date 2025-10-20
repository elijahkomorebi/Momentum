#include <stdio.h>
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
#include <raylib.h>
#include "momentum.h"

int main() {
    InitWindow(800, 600, "Momentum");
    SetExitKey(0);

    lua_State *L = luaL_newstate();

    luaL_openlibs(L);
    luaL_requiref(L, "momentum", luaopen_momentum, 1);
    lua_pop(L, 1);

    if (luaL_dofile(L, "main.lua") != LUA_OK) {
        const char *error = lua_tostring(L, -1);

        fprintf(stderr, "%s\n", error);
        lua_close(L);
        CloseWindow();

        return -1;
    }

    if (!lua_isfunction(L, -1)) {
        lua_close(L);
        CloseWindow();

        return -1;
    }

    int updateRef = luaL_ref(L, LUA_REGISTRYINDEX);

    while (!WindowShouldClose()) {
        lua_rawgeti(L, LUA_REGISTRYINDEX, updateRef);

        if (lua_pcall(L, 0, 0, 0) != LUA_OK) {
            const char *error = lua_tostring(L, -1);

            fprintf(stderr, "%s\n", error);
            CloseWindow();
        }
    }

    lua_close(L);
    CloseWindow();

    return 0;
}
