cmake_minimum_required(VERSION 3.19)
project(task1)

set(CMAKE_CXX_STANDARD 14)

include_directories("include")

file(GLOB sources
        "${PROJECT_SOURCE_DIR}/include/*.h"
        "${PROJECT_SOURCE_DIR}/source/*.cpp")

add_executable(task1 ${sources})