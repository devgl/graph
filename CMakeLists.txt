cmake_minimum_required(VERSION 3.20)

project(Graph)

add_executable(run main.cpp "Graph.hpp" "Graph.cpp" "Node.hpp" "Node.cpp" "ResourceCache.cpp")
target_compile_definitions(run PUBLIC cxx_std_20)