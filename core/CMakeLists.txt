add_library(chip8_core STATIC
    src/chip8.cpp
)

target_include_directories(chip8_core
    PUBLIC  include
    PRIVATE src
)

target_compile_features(chip8_core PUBLIC cxx_std_20)
target_compile_options(chip8_core PRIVATE -Wall -Wextra -Wpedantic)