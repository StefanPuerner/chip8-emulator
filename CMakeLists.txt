cmake_minimum_required(VERSION 3.21)

project(chip8 VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(core)
add_subdirectory(cli)

