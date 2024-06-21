# chip8 cmake file

# CMake minimum version required
cmake_minimum_required(VERSION 3.15)

# Set enviroment
set(PACKAGE_NAME    "chip8")
set(PACKAGE_VERSION "0.1.0")


# Project name and language
project(${PACKAGE_NAME}
        LANGUAGES C CXX
        VERSION ${PACKAGE_VERSION})

add_subdirectory(src)