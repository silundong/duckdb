cmake_minimum_required(VERSION 2.8.12...3.29)
project(embedded_example)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)

include_directories(../../src/include)
link_directories(../../build/debug/src)

add_executable(example main.cpp)

target_compile_options(example PRIVATE -g -O0 -Wall -fsanitize=address)
target_link_options(example PRIVATE -fsanitize=address)

target_link_libraries(example duckdb)