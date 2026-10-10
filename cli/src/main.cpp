#include <cstdint>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "chip8/chip8.hpp"

int main(int argc, char* argv[]) {
  if (argc != 2) {
    std::cerr << "Error: wrong nº of parameters, try -h/--help.\n";
    return 1;
  }
  if (std::string(argv[1]) == "--help" || std::string(argv[1]) == "-h") {
    std::cout << "Use: " << argv[0] << " <ROM_FILE>\n";
    return 0;
  }
  std::string route = argv[1];
  std::ifstream rom_file(route, std::ios::binary);
  if (!rom_file) {
    std::cerr << "Error: couldn't open ROM file.\n";
    return 1;
  }
  size_t file_size = std::filesystem::file_size(route);
  if (file_size == 0) {
    std::cerr << "Error: ROM is empty.\n";
    return 1;
  }
  std::vector<uint8_t> bytes;
  bytes.resize(file_size);
  std::cout << argv[1] << " has been read ";
  if (rom_file
          .read(reinterpret_cast<char*>(bytes.data()),
                static_cast<std::streamsize>(file_size))
          .gcount() != static_cast<std::streamsize>(file_size)) {
    std::cerr << "incorrectly.(" << bytes.size() << ") bytes\n";
    return 1;
  }
  std::cout << "correctly(" << bytes.size() << ") bytes\n";
  return 0;
}