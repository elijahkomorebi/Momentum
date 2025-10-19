cmake_minimum_required(VERSION 3.1)
project(Momentum C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(MOMENTUM_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(MOMENTUM_LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(LUA_SOURCE_DIR ${MOMENTUM_LIB_DIR}/lua)
set(RAYLIB_DIR ${MOMENTUM_LIB_DIR}/raylib)
set(RAYLIB_SOURCE_DIR ${RAYLIB_DIR}/src)

file(GLOB MOMENTUM_SOURCE ${MOMENTUM_SOURCE_DIR}/*.c)
file(GLOB LUA_SOURCE ${LUA_SOURCE_DIR}/*.c)

list(FILTER LUA_SOURCE EXCLUDE REGEX "lua\\.c$")

add_executable(momentum
    ${MOMENTUM_SOURCE}
    ${LUA_SOURCE}
)

target_include_directories(momentum PRIVATE
    ${MOMENTUM_SOURCE_DIR}
    ${LUA_SOURCE_DIR}
    ${RAYLIB_SOURCE_DIR}
)

add_subdirectory(${RAYLIB_DIR})

target_link_libraries(momentum PRIVATE
    m
    raylib
    pthread
    dl
    rt
    X11
    GL
)
