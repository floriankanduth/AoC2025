cmake_minimum_required(VERSION 3.16)
project(aoc LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SRC_FILES src/*.cpp)

add_executable(aoc ${SRC_FILES})
target_include_directories(aoc PRIVATE inc)

# Copy input files if needed
file(COPY input DESTINATION ${CMAKE_BINARY_DIR})

enable_testing()

add_test(NAME print_help
        COMMAND aoc -h)