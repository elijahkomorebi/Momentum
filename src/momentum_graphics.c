#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
#include <raylib.h>
#include <raymath.h>
#include <rlgl.h>
#include "momentum_graphics.h"

static MomentumTransformStack g_transform = {0};

static void initTransformStack() {
    g_transform.top = 0;
    g_transform.stack[0] = MatrixIdentity();
}

static void pushTransform() {
    if (g_transform.top < MOMENTUM_TRANSFORM_STACK_SIZE - 1) {
        g_transform.stack[g_transform.top + 1] = g_transform.stack[g_transform.top];
        g_transform.top++;
    }
}

static void popTransform() {
    if (g_transform.top > 0) {
        g_transform.top--;
    }
}

static void translateTransform(double x, double y) {
    Matrix t = MatrixTranslate(x, y, 0);
    g_transform.stack[g_transform.top] = MatrixMultiply(t, g_transform.stack[g_transform.top]);
}

static void rotateTransform(double a) {
    Matrix t = MatrixRotateZ(a);
    g_transform.stack[g_transform.top] = MatrixMultiply(t, g_transform.stack[g_transform.top]);
}

static void scaleTransform(double x, double y) {
    Matrix t = MatrixScale(x, y, 1);
    g_transform.stack[g_transform.top] = MatrixMultiply(t, g_transform.stack[g_transform.top]);
}

static void applyTransform() {
    rlMultMatrixf(MatrixToFloat(g_transform.stack[g_transform.top]));
}

int momentum_graphics_beginDrawing(lua_State *L) {
    BeginDrawing();
    rlPushMatrix();

    return 0;
}

int momentum_graphics_endDrawing(lua_State *L) {
    rlPopMatrix();
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

int momentum_graphics_push(lua_State *L) {
    pushTransform();
    applyTransform();

    return 0;
}

int momentum_graphics_pop(lua_State *L) {
    popTransform();
    applyTransform();

    return 0;
}

int momentum_graphics_translate(lua_State *L) {
    double x = luaL_checknumber(L, 1);
    double y = luaL_checknumber(L, 2);

    translateTransform(x, y);
    applyTransform();

    return 0;
}

int momentum_graphics_rotate(lua_State *L) {
    double a = luaL_checknumber(L, 1);

    rotateTransform(a);
    applyTransform();
    
    return 0;
}

int momentum_graphics_scale(lua_State *L) {
    double x = luaL_checknumber(L, 1);
    double y = luaL_checknumber(L, 2);

    scaleTransform(x, y);
    applyTransform();

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
    {"push", momentum_graphics_push},
    {"pop", momentum_graphics_pop},
    {"translate", momentum_graphics_translate},
    {"rotate", momentum_graphics_rotate},
    {"scale", momentum_graphics_scale},
    {"drawText", momentum_graphics_drawText},
    {"drawCircle", momentum_graphics_drawCircle},
    {"drawRectangle", momentum_graphics_drawRectangle},
    {"drawImage", momentum_graphics_drawImage},
    {NULL, NULL}
};

int luaopen_momentum_graphics(lua_State *L) {
    initTransformStack();
    luaL_newmetatable(L, "MomentumImage");
    lua_pushcfunction(L, momentum_graphics_deleteImage);
    lua_setfield(L, -2, "__gc");
    lua_pop(L, 1);

    luaL_newlib(L, momentum_graphics_reg);

    return 1;
}
