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
project(HorusGL
        VERSION 1.0.0
        DESCRIPTION "A Simple OpenGL C++ Starter Project Using CMake"
        HOMEPAGE_URL "https://github.com/thiago-rezende/horus-gl"
        LANGUAGES CXX)

# Generate an config.h file based on config.in file
configure_file(${CMAKE_SOURCE_DIR}/horus_gl/config.in ${CMAKE_SOURCE_DIR}/horus_gl/config.h @ONLY NEWLINE_STYLE LF)

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

# Setting the path to the vendor folder
set(VENDOR ${CMAKE_SOURCE_DIR}/vendor)

# Spdlog options
option(SPDLOG_ENABLE_PCH "Build static or shared library using precompiled header to speed up compilation time" ON)

# GLFW options
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)
option(GLFW_BUILD_EXAMPLES "Build the GLFW example programs" OFF)
option(GLFW_BUILD_TESTS "Build the GLFW test programs" OFF)
option(GLFW_BUILD_DOCS "Build the GLFW documentation" OFF)
option(GLFW_INSTALL "Generate installation target" OFF)
option(GLFW_VULKAN_STATIC "Assume the Vulkan loader is linked with the application" OFF)
option(USE_MSVC_RUNTIME_LIBRARY_DLL "Use MSVC runtime library DLL" ON)

# GLAD options
option(GLAD_USE_MSVC_DYNAMIC_LINKED_RUNTIME "Uses MSVC dynamic linked runtime" ON)

# GLM options
option(BUILD_STATIC_LIBS "Build GLM as static lib" OFF)
option(BUILD_SHARED_LIBS "Build GLM as shared lib" OFF)

# STB Image options
option(STB_IMAGE_MSVC_DYNAMIC_LINKED_RUNTIME "Uses MSVC dynamic linked runtime" ON)

# Adding the vendor libs directories
add_subdirectory(${VENDOR}/spdlog)
add_subdirectory(${VENDOR}/glfw)
add_subdirectory(${VENDOR}/glad)
add_subdirectory(${VENDOR}/glm)
add_subdirectory(${VENDOR}/stb_image)

# Setting project options
option(HORUS_GL_USE_MSVC_DYNAMIC_LINKED_RUNTIME "Uses MSVC dynamic linked runtime" ON)

# Setting the project folders
add_subdirectory(horus_gl)

# Visual Studio Config
if(MSVC)
    ## Enable folders
    set_property(GLOBAL PROPERTY USE_FOLDERS ON)
    ## Application
    set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT horus_gl)
    set_property(TARGET horus_gl PROPERTY FOLDER "Application")
    ## Utils
    set_property(TARGET copy_resources_horus_gl PROPERTY FOLDER "Utils")
    ## Vendor
    # Spdlog
    set_property(TARGET spdlog PROPERTY FOLDER "Vendor/Spdlog")
endif(MSVC)
