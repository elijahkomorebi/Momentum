#ifndef MOMENTUM_GRAPHICS_H
#define MOMENTUM_GRAPHICS_H

#include <lauxlib.h>
#include <lualib.h>
#include <raylib.h>

int luaopen_momentum_graphics(lua_State *L);
int momentum_graphics_beginDrawing(lua_State *L);
int momentum_graphics_endDrawing(lua_State *L);
int momentum_graphics_clearBackground(lua_State *L);
int momentum_graphics_drawText(lua_State *L);
int momentum_graphics_drawCircle(lua_State *L);

#endif
