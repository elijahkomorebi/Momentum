#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
#include <raylib.h>
#include "momentum_input.h"

int momentum_input_isKeyDown(lua_State *L) {
    int key = luaL_checkinteger(L, 1);

    if (IsKeyDown(key)) {
        lua_pushboolean(L, 1);
    } else {
        lua_pushboolean(L, 0);
    }

    return 1;
}

int momentum_input_isMouseDown(lua_State *L) {
    int button = luaL_checkinteger(L, 1);

    if (IsMouseButtonDown(button)) {
        lua_pushboolean(L, 1);
    } else {
        lua_pushboolean(L, 0);
    }
    
    return 1;
}

int momentum_input_getMouseX(lua_State *L) {
    lua_pushinteger(L, GetMouseX());

    return 1;
}

int momentum_input_getMouseY(lua_State *L) {
    lua_pushinteger(L, GetMouseY());

    return 1;
}

const luaL_Reg momentum_input_reg[] = {
    {"isKeyDown", momentum_input_isKeyDown},
    {"isMouseDown", momentum_input_isMouseDown},
    {"getMouseX", momentum_input_getMouseX},
    {"getMouseY", momentum_input_getMouseY},
    {NULL, NULL}
};

int luaopen_momentum_input(lua_State *L) {
    luaL_newlib(L, momentum_input_reg);

    return 1;
}
