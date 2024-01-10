# INITIAL CMAKELISTS.TXT
cmake_minimum_required(VERSION 3.20)
# PROJECT SETUP
project(main VERSION 0.0.1 LANGUAGES CXX)

# C++ STANDARD
set(CMAKE_CXX_VERSION 17)
set(CMAKE_CXX_VERSION_REQUIRED ON)
# EXPORT COMPILE COMMANDS FOR CLANGD AND OTHER LSPs
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# ADD THE FMT LIBRARY
add_subdirectory(fmt)

# SETUP THE EXECUTABLE
add_executable(main src/main.cpp)
target_link_libraries(main PRIVATE fmt)
target_include_directories(main PRIVATE ${CMAKE_CURRENT_LIST_DIR}/include/)
target_compile_options(main PRIVATE
	-std=c++17
    -Wall
    -Wextra
    -Werror
    -Wunused-variable
    -Wunused-parameter
    -Wunused-function
    -Wunused-but-set-variable
    -Wshadow
    -Wunreachable-code
    -pedantic-errors
)