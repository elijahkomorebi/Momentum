#ifndef MOMENTUM_INPUT_H
#define MOMENTUM_INPUT_H

#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>

int luaopen_momentum_input(lua_State *L);
int momentum_input_isKeyDown(lua_State *L);
int momentum_input_isMouseDown(lua_State *L);
int momentum_input_getMouseX(lua_State *L);
int momentum_input_getMouseY(lua_State *L);

#endif
