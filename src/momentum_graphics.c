#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
#include <raylib.h>
#include "momentum_graphics.h"

int momentum_graphics_beginDrawing(lua_State *L) {
    BeginDrawing();

    return 0;
}

int momentum_graphics_endDrawing(lua_State *L) {
    EndDrawing();

    return 0;
}

int momentum_graphics_clearBackground(lua_State *L) {
    double r = luaL_checknumber(L, 1);
    double g = luaL_checknumber(L, 1);
    double b = luaL_checknumber(L, 1);
    double a = luaL_checknumber(L, 1);

    ClearBackground((Color){r, g, b, a});

    return 1;
}

int momentum_graphics_drawText(lua_State *L) {
    const char *text = luaL_checkstring(L, 1);
    double x = luaL_checknumber(L, 2);
    double y = luaL_checknumber(L, 3);
    double r = luaL_checknumber(L, 4);
    double g = luaL_checknumber(L, 5);
    double b = luaL_checknumber(L, 6);
    double a = luaL_checknumber(L, 7);

    DrawText(text, x, y, 20, (Color){r, g, b, a});

    return 0;
}

int momentum_graphics_drawCircle(lua_State *L) {
    double x = luaL_checknumber(L, 1);
    double y = luaL_checknumber(L, 2);
    double s = luaL_checknumber(L, 3);
    double r = luaL_checknumber(L, 4);
    double g = luaL_checknumber(L, 5);
    double b = luaL_checknumber(L, 6);
    double a = luaL_checknumber(L, 7);

    DrawCircle(x, y, s, (Color){r, g, b, a});

    return 0;
}

const luaL_Reg momentum_graphics_reg[] = {
    {"beginDrawing", momentum_graphics_beginDrawing},
    {"endDrawing", momentum_graphics_endDrawing},
    {"clearBackground", momentum_graphics_clearBackground},
    {"drawText", momentum_graphics_drawText},
    {"drawCircle", momentum_graphics_drawCircle},
    {NULL, NULL}
};

int luaopen_momentum_graphics(lua_State *L) {
    luaL_newlib(L, momentum_graphics_reg);

    return 1;
}
