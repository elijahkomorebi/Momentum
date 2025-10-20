#ifndef MOMENTUM_GRAPHICS_H
#define MOMENTUM_GRAPHICS_H

#include <lauxlib.h>
#include <lualib.h>
#include <raylib.h>

typedef struct {
    Texture2D texture;
} MomentumImage;

int luaopen_momentum_graphics(lua_State *L);

int momentum_graphics_beginDrawing(lua_State *L);
int momentum_graphics_endDrawing(lua_State *L);
int momentum_graphics_clearBackground(lua_State *L);

int momentum_graphics_newImage(lua_State *L);

int momentum_graphics_deleteImage(lua_State *L);

int momentum_graphics_drawText(lua_State *L);
int momentum_graphics_drawCircle(lua_State *L);
int momentum_graphics_drawRectangle(lua_State *L);
int momentum_graphics_drawImage(lua_State *L);

#endif
