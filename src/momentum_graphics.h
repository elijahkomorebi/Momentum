#ifndef MOMENTUM_GRAPHICS_H
#define MOMENTUM_GRAPHICS_H

#define MOMENTUM_TRANSFORM_STACK_SIZE 64

#include <lauxlib.h>
#include <lualib.h>
#include <raylib.h>

typedef struct {
    Texture2D texture;
} MomentumImage;

typedef struct {
    Matrix stack[MOMENTUM_TRANSFORM_STACK_SIZE];
    int top;
} MomentumTransformStack;

int luaopen_momentum_graphics(lua_State *L);

int momentum_graphics_beginDrawing(lua_State *L);
int momentum_graphics_endDrawing(lua_State *L);
int momentum_graphics_clearBackground(lua_State *L);

int momentum_graphics_newImage(lua_State *L);

int momentum_graphics_deleteImage(lua_State *L);

int momentum_graphics_push(lua_State *L);
int momentum_graphics_pop(lua_State *L);
int momentum_graphics_translate(lua_State *L);

int momentum_graphics_drawText(lua_State *L);
int momentum_graphics_drawCircle(lua_State *L);
int momentum_graphics_drawRectangle(lua_State *L);
int momentum_graphics_drawImage(lua_State *L);

#endif
