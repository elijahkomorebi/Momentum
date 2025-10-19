#ifndef MOMENTUM_TIME_H
#define MOMENTUM_TIME_H

#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>

int luaopen_momentum_time(lua_State *L);
int momentum_time_getDelta(lua_State *L);

#endif
