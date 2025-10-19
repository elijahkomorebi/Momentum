#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
#include "momentum_window.h"
#include "momentum_graphics.h"
#include "momentum_time.h"
#include "momentum_input.h"

int luaopen_momentum(lua_State *L) {
    lua_newtable(L);

    luaopen_momentum_window(L);
    lua_setfield(L, -2, "window");
    luaopen_momentum_graphics(L);
    lua_setfield(L, -2, "graphics");
    luaopen_momentum_time(L);
    lua_setfield(L, -2, "time");
    luaopen_momentum_input(L);
    lua_setfield(L, -2, "input");

    return 1;
}
