# CHIP-8-EMULATOR
A CHIP-8 emulator in C++ with a Qt Quick interface, built step by step.

## State of the project:

- [x] 1. Skeleton of the project
- [ ] 2. State of the core
  - [ ] Memory
  - [ ] first load into memoryç
  - [ ] first ROM load and state restart
- [ ] 3. Fetch, decode and 6 basic opcodes
- [ ] 4. Remaining opcodes, by blocks
- [ ] 5. Frame loop
- [ ] 6. QML and adapter class (singlethread)
- [ ] 7. Keyboard and sounds
- [ ] 8. Quirks and configurable speeds
- [ ] 9. Own thread for core alone
- [ ] 10. Final tests

## Architecture 
The first approach is a single-threaded implementation, three targets, core
as a library written in c++, and cli and app as two independent clients.
Core is agnostic to Qt. cli is a terminal client for development and debugging.

```text
.
├── app
│   ├── CMakeLists.txt
│   ├── qml
│   └── src
├── cli
│   ├── CMakeLists.txt
│   └── src
│       └── main.cpp
├── CMakeLists.txt
├── core
│   ├── CMakeLists.txt
│   ├── include
│   │   └── chip8
│   │       └── chip8.hpp
│   └── src
│       └── chip8.cpp
├── roms
│   └── 2-ibm-logo.ch8
└── tests
```

## References
- [The CHIP-8 guide from Tobias V. Langhoff](https://tobiasvl.github.io/blog/write-a-chip-8-emulator/)
- [Timendus Rom test suite for CHIP-8](https://github.com/Timendus/chip8-test-suite)

## Requirements
- C++20 Compiler
- CMake 3.21+

## Building and Running

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build
./build/cli/chip8_cli
```