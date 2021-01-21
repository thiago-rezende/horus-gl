# Include dirs
set(HORUS_GL_INCLUDE_DIRS
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# Header files
set(HORUS_GL_HEADERS
    "hglpch.h"
    "horus/horus.h"
    "horus/core/logger.h"
)

# Source files
set(HORUS_GL_SOURCES
    "main.cpp"
    "horus/core/logger.cpp"
)

# horus_gl executable
add_executable(horus_gl ${HORUS_GL_SOURCES})

# Check for MSVC
if(MSVC)
    # Check for dynamic runtime
    if(HORUS_GL_USE_MSVC_DYNAMIC_LINKED_RUNTIME)
        set_property(TARGET horus_gl PROPERTY
            MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL"
        )
    else()
        set_property(TARGET horus_gl PROPERTY
            MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>"
        )
    endif()
endif()

# Definitions
target_compile_definitions(horus_gl
PUBLIC
    $<$<CONFIG:Debug>:ENABLE_LOG_MACROS>
)

# Setting the pre compiled header
target_precompile_headers(horus_gl PUBLIC
    "$<$<COMPILE_LANGUAGE:CXX>:${CMAKE_CURRENT_SOURCE_DIR}/hglpch.h>"
)

# HorusGL properties
set_target_properties(horus_gl
PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED 17
)

# HorusGL include dirs
target_include_directories(horus_gl
PUBLIC
    ${HORUS_GL_INCLUDE_DIRS}
)

# HorusGL libraries
target_link_libraries(horus_gl
PUBLIC
    spdlog::spdlog_header_only
)

# Setting custom commandos to copy all needed files to the right location
add_custom_target(copy_resources_horus_gl ALL
    COMMAND cmake -E copy_directory ${CMAKE_SOURCE_DIR}/horus_gl/assets ${CMAKE_BINARY_DIR}/bin/assets
    COMMAND cmake -E copy_directory ${CMAKE_SOURCE_DIR}/horus_gl/assets ${CMAKE_SOURCE_DIR}/bin/assets
    DEPENDS horus_gl)

# Setting the install command to the app
install(TARGETS horus_gl RUNTIME DESTINATION bin)
install(TARGETS horus_gl LIBRARY DESTINATION lib)
