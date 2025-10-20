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

int momentum_graphics_newImage(lua_State *L) {
    const char *path = luaL_checkstring(L, 1);
    MomentumImage *image = lua_newuserdata(L, sizeof(MomentumImage));
    image->texture = LoadTexture(path);

    luaL_getmetatable(L, "MomentumImage");
    lua_setmetatable(L, -2);

    return 1;
}

int momentum_graphics_deleteImage(lua_State *L) {
    MomentumImage *image = luaL_checkudata(L, 1, "MomentumImage");

    UnloadTexture(image->texture);

    return 0;
}

int momentum_graphics_drawText(lua_State *L) {
    const char *text = luaL_checkstring(L, 1);
    double x = luaL_checknumber(L, 2);
    double y = luaL_checknumber(L, 3);
    double s = luaL_checknumber(L, 4);
    double r = luaL_checknumber(L, 5);
    double g = luaL_checknumber(L, 6);
    double b = luaL_checknumber(L, 7);
    double a = luaL_checknumber(L, 8);

    DrawText(text, x, y, s, (Color){r, g, b, a});

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

int momentum_graphics_drawRectangle(lua_State *L) {
    double x = luaL_checknumber(L, 1);
    double y = luaL_checknumber(L, 2);
    double w = luaL_checknumber(L, 3);
    double h = luaL_checknumber(L, 4);
    double r = luaL_checknumber(L, 5);
    double g = luaL_checknumber(L, 6);
    double b = luaL_checknumber(L, 7);
    double a = luaL_checknumber(L, 8);

    DrawRectangle(x, y, w, h, (Color){r, g, b, a});

    return 0;
}

int momentum_graphics_drawImage(lua_State *L) {
    MomentumImage *image = luaL_checkudata(L, 1, "MomentumImage");
    double x = luaL_checknumber(L, 2);
    double y = luaL_checknumber(L, 3);
    double r = luaL_checknumber(L, 4);
    double g = luaL_checknumber(L, 5);
    double b = luaL_checknumber(L, 6);
    double a = luaL_checknumber(L, 7);

    DrawTexture(image->texture, x, y, (Color){r, g, b, a});

    return 0;
}

const luaL_Reg momentum_graphics_reg[] = {
    {"beginDrawing", momentum_graphics_beginDrawing},
    {"endDrawing", momentum_graphics_endDrawing},
    {"clearBackground", momentum_graphics_clearBackground},
    {"newImage", momentum_graphics_newImage},
    {"deleteImage", momentum_graphics_deleteImage},
    {"drawText", momentum_graphics_drawText},
    {"drawCircle", momentum_graphics_drawCircle},
    {"drawRectangle", momentum_graphics_drawRectangle},
    {"drawImage", momentum_graphics_drawImage},
    {NULL, NULL}
};

int luaopen_momentum_graphics(lua_State *L) {
    luaL_newmetatable(L, "MomentumImage");
    lua_pushcfunction(L, momentum_graphics_deleteImage);
    lua_setfield(L, -2, "__gc");
    lua_pop(L, 1);

    luaL_newlib(L, momentum_graphics_reg);

    return 1;
}
