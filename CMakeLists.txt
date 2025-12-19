cmake_minimum_required(VERSION 3.16)
project(AoC LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR}/inc)

# Copy input folder to build directory
file(COPY ${CMAKE_SOURCE_DIR}/input DESTINATION ${CMAKE_BINARY_DIR})

add_subdirectory(src)

enable_testing()
file(GLOB DAY_FILES CONFIGURE_DEPENDS "${CMAKE_BINARY_DIR}/src/day*")
foreach(DAY_FILE ${DAY_FILES})
    add_test(
            NAME ${DAY_FILE}_runs
            COMMAND ${DAY_FILE}
    )
endforeach()