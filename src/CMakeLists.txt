# Collect dayXX.cpp files
file(GLOB DAY_FILES CONFIGURE_DEPENDS "day*.cpp")

foreach(DAY_FILE ${DAY_FILES})
    # Executable name (day01.cpp → day01)
    get_filename_component(EXENAME ${DAY_FILE} NAME_WE)

    # Create executable
    add_executable(${EXENAME} ${DAY_FILE})

    # Include project headers
    target_include_directories(${EXENAME} PRIVATE ${CMAKE_SOURCE_DIR}/inc)
endforeach()
