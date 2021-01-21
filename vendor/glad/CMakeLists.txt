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
project(GLAD
        VERSION 0.1.34
        DESCRIPTION "Multi-Language GL/GLES/EGL/GLX/WGL Loader-Generator based on the official specs"
        HOMEPAGE_URL "https://github.com/Dav1dde/glad"
        LANGUAGES C)

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
option(GLAD_USE_MSVC_DYNAMIC_LINKED_RUNTIME "Uses MSVC dynamic linked runtime" OFF)

# Include dirs
set(GLAD_INCLUDE_DIRS
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Header files
set(GLAD_HEADERS
    "include/glad/glad.h"
    "include/KHR/khrplatform.h"
)

# Source files
set(GLAD_SOURCES
    "src/glad.c"
)

# GLAD library
add_library(glad ${GLAD_SOURCES})

# Check for MSVC
if(MSVC)
    # Check for dynamic runtime
    if(GLAD_USE_MSVC_DYNAMIC_LINKED_RUNTIME)
        set_property(TARGET glad PROPERTY
            MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL"
        )
    else()
        set_property(TARGET glad PROPERTY
            MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>"
        )
    endif()
endif()

# GLAD include dirs
target_include_directories(glad
PUBLIC
    ${GLAD_INCLUDE_DIRS}
)

# Setting the install command to the app
install(TARGETS glad RUNTIME DESTINATION bin)
install(TARGETS glad LIBRARY DESTINATION lib)
