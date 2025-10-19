#ifndef MOMENTUM_WINDOW_H
#define MOMENTUM_WINDOW_H

#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
#include <raylib.h>

int luaopen_momentum_window(lua_State *L);
int momentum_window_close(lua_State *L);
int momentum_window_setTargetFPS(lua_State *L);
int momentum_window_getWidth(lua_State *L);
int momentum_window_getHeight(lua_State *L);

#endif
