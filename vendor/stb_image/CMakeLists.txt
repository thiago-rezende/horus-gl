# Minimum version to run the script
cmake_minimum_required(VERSION 3.16.0)

# Setting build type
set(DEFAULT_BUILD_TYPE "Debug")
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  message(STATUS "Setting build type to '${DEFAULT_BUILD_TYPE}' as none was specified.")
  set(CMAKE_BUILD_TYPE "${DEFAULT_BUILD_TYPE}" CACHE
      STRING "Choose the type of build." FORCE)
  # Set the possible values of build type for cmake-gui
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS
    "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

# Setting up the project name and version
project(STBImage
        VERSION 2.26.0
        DESCRIPTION "Public domain image loader"
        HOMEPAGE_URL "https://github.com/nothings/stb"
        LANGUAGES CXX)

# Setting the install prefix
set(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR})

# First for the generic no-config case (e.g. with mingw)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
# Second, for multi-config builds (e.g. msvc)
foreach(OUTPUT_CONFIG ${CMAKE_CONFIGURATION_TYPES})
    string( TOUPPER ${OUTPUT_CONFIG} OUTPUT_CONFIG )
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_${OUTPUT_CONFIG} ${CMAKE_BINARY_DIR}/bin)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_${OUTPUT_CONFIG} ${CMAKE_BINARY_DIR}/lib)
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${OUTPUT_CONFIG} ${CMAKE_BINARY_DIR}/lib)
endforeach(OUTPUT_CONFIG CMAKE_CONFIGURATION_TYPES)

# Setting project options
option(STB_IMAGE_MSVC_DYNAMIC_LINKED_RUNTIME "Uses MSVC dynamic linked runtime" OFF)

# Include dirs
set(STB_IMAGE_INCLUDE_DIRS
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# Header files
set(STB_IMAGE_HEADERS
    "stb_image.h"
)

# Source files
set(STB_IMAGE_SOURCES
    "stb_image.cpp"
)

# STB_IMAGE library
add_library(stb_image ${STB_IMAGE_SOURCES})

# Check for MSVC
if(MSVC)
    # Check for dynamic runtime
    if(STB_IMAGE_MSVC_DYNAMIC_LINKED_RUNTIME)
        set_property(TARGET stb_image PROPERTY
            MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL"
        )
    else()
        set_property(TARGET stb_image PROPERTY
            MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>"
        )
    endif()
endif()

# STB_IMAGE include dirs
target_include_directories(stb_image
PUBLIC
    ${STB_IMAGE_INCLUDE_DIRS}
)

# Setting the install command to the app
install(TARGETS stb_image RUNTIME DESTINATION bin)
install(TARGETS stb_image LIBRARY DESTINATION lib)
