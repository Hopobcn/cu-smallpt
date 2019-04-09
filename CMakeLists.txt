# GOOD CMake documentation: https://cliutils.gitlab.io/modern-cmake/
cmake_minimum_required(VERSION 3.12)

project(cu-smallpt VERSION 1.0
                   DESCRIPTION "CUDA path-based rendering algorithm"
                   LANGUAGES CXX CUDA)

# Default build type (Release)
set(DEFAULT_BUILD_TYPE "Release")
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    message(STATUS "Setting build type to '${DEFAULT_BUILD_TYPE}' as none was specified.")
    set(CMAKE_BUILD_TYPE "${DEFAULT_BUILD_TYPE}" CACHE STRING "Choose the type of build." FORCE)
    # Set the possible values of build type for cmake-gui
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS
        "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

# IDE support: Xcode & VS require folder support for correctly displaying project hierarchy
set_property(GLOBAL PROPERTY USE_FOLDERS ON)


add_subdirectory(src)