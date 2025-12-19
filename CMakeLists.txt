cmake_minimum_required(VERSION 3.18)
project(AoC LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR}/inc)

# Copy input folder to build directory
file(COPY ${CMAKE_SOURCE_DIR}/input DESTINATION ${CMAKE_BINARY_DIR})

add_subdirectory(src)

enable_testing()
set(DAY_TARGETS)

foreach (day RANGE 1 12) # only 12 days of AoC this year :(
    set(tgt "day${day}")
    set(src "${CMAKE_SOURCE_DIR}/src/${tgt}.cpp")
    if(EXISTS "${src}")
        list(APPEND DAY_TARGETS ${tgt})
    endif ()
endforeach ()

enable_testing()

foreach (tgt ${DAY_TARGETS})
    add_test(NAME ${tgt}_runs
            COMMAND $<TARGET_FILE:${tgt}>)
endforeach ()