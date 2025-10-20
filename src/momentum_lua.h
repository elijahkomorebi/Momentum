#ifndef MOMENTUM_LUA_H
#define MOMENTUM_LUA_H

#include <lauxlib.h>
#include <lualib.h>
#include <raylib.h>

int luaopen_momentum_lua(lua_State *L);

int momentum_lua_version(lua_State *L);
int momentum_lua_memory(lua_State *L);

#endif
