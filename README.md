# C++ Binary Project Template

This repository serves as a simple template for a C++ binary project.

## Overview

This project is a starting point for creating C++ projects that produce executable binaries. It includes a basic directory structure and a CMake-based build system.

## Features

- Minimalistic C++ project structure.
- CMake-based build system for easy project configuration and building.
- Placeholder `main.cpp` file as a starting point for your project.
- Easily customizable for adding additional source files, libraries, and dependencies.

## Dependencies

This project utilizes the following external library: fmt

### [fmt](https://github.com/fmtlib/fmt)


## Getting Started

### Prerequisites

- CMake (version 3.20 or higher)
- C++ compiler supporting at least C++17 standard (e.g., GCC, Clang, MSVC)

### Building

1. Clone this repository:

    ```shell
    git clone https://github.com/i-Sage/main.git
    cd main
    ```

2. Create a `build` directory:

    ```shell
    mkdir build
    cd build
    ```

3. Run CMake to configure the project:

    ```shell
    cmake ..
    ```

4. Build the project:

    ```shell
    cmake --build .
    ```

### Usage

1. Modify the `main.cpp` file or add your own source files in the project directory.
2. Use CMake commands to build and manage your project.

## License

This project is licensed under the MIT License - see the [LICENSE](https://en.wikipedia.org/wiki/MIT_License) for details.

## The fmt library
I want to give a huge shout out for the fmt library. It is a great library that makes formatting strings and io operations in C++ a breeze. I highly recommend it for any C++ project.

[useage](https://fmt.dev/latest/usage.html)