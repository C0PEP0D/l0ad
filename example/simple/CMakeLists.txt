cmake_minimum_required(VERSION 3.11)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(simple)

# Build target
add_executable(simple main.cpp)
target_include_directories(simple PRIVATE .)

# Link modules
target_include_directories(simple PRIVATE ../../include)
