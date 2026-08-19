program_name := "main"
build_dir := ".build"

_:
  @just --list

# Download project dependencies
init:
  @mkdir -p lib
  # wget https://github.com/nlohmann/json/releases/latest/download/json.hpp -O lib/json.hpp
  # wget https://raw.githubusercontent.com/marzer/tomlplusplus/master/toml.hpp -O lib/toml.hpp

# Builds the project in release mode. Available options: "main", "debug", "db" (for compiledb); default: "main"
build target="main":
  @just _build-{{target}}

_build-main:
  @mkdir -p {{build_dir}}
  bear -- ccache clang++ -std=c++20 -Wall -O2 -Iinclude -Ilib src/*.cpp -o ./{{build_dir}}/{{program_name}}

_build-debug:
  @mkdir -p {{build_dir}}
  bear -- ccache clang++ -std=c++20 -Wall -O0 -Ddebug -Iinclude -Ilib src/*.cpp -o ./{{build_dir}}/{{program_name}}

# Build and run the project for debugging
run *ARGS: _build-debug
  @echo ""
  @echo "--- PROGRAM START ---"
  @./{{build_dir}}/{{program_name}} {{ARGS}}
  @echo "--- PROGRAM END ---"

# Build and release the project (copy to bin directory)
# release: build
#   cp ./{{build_dir}}/{{program_name}} ~/bin/{{program_name}}

# Remove build artifacts
clean:
  rm -rf ./{{build_dir}}
