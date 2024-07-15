cmake_minimum_required(VERSION 3.10)

project(md2html VERSION 0.1 LANGUAGES CXX)

# Set the C++ lang version
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Add executable
add_executable(md2html src/main.cpp)
