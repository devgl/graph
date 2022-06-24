cmake_minimum_required(VERSION 3.20)

project(Graph)

add_subdirectory(LuaPlugin)


add_executable(run main.cpp "Graph.hpp" "Graph.cpp" "Node.hpp" "Node.cpp" "ResourceCache.cpp" "Graph.lua.cpp")
target_link_libraries(run PRIVATE LibLua)
target_compile_definitions(run PUBLIC cxx_std_20)
target_compile_definitions(run PUBLIC SCRIPT_PATH="${CMAKE_SOURCE_DIR}/scripts/")
target_precompile_headers(run PUBLIC "pch.hpp")

