# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Project name
project(OOPS_Basic)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add source files
file(GLOB SOURCES "./*.cxx")

# Add executable
add_executable(basic ${SOURCES})

# Include directories
include_directories(include)