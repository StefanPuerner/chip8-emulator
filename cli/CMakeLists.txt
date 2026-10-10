add_executable(chip8_cli
    src/main.cpp
)

target_link_libraries(chip8_cli PRIVATE chip8_core)
target_compile_options(chip8_cli PRIVATE -Wall -Wextra -Wpedantic)