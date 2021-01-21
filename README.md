# HorusGL - OpenGL Starter Project
![license-badge] ![cpp-badge] ![cmake-badge]
<!-- PROJECT LOGO -->
<br />
<div align="center">
  <a href="https://github.com/thiago-rezende/horus-gl">
    <img src=".github/logo.png" alt="Logo" width="100" height="100">
  </a>

  <h3 align="center">HorusGL - OpenGL Starter Project</h3>
  <p align="center">
    A Simple OpenGL Starter Project Using CMake
    <br />
    <a href="https://github.com/thiago-rezende/horus-gl/issues">Report Bug</a>
    ·
    <a href="https://github.com/thiago-rezende/horus-gl/issues">Request Feature</a>
    .
    <a href="https://github.com/thiago-rezende/horus-gl/actions">Continuous Integration</a>
  </p>
</div>

 - Libraries Included
    - [Spdlog][spdlog-url]
    - [GLFW][glfw-url]
    - [GLAD][glad-url]
    - [GLM][glm-url]
    - [ImGui][imgui-url]
    - [STB Image][stb_image-url]

 - Project structure
 ```
    .
    ├── .github                       # Repository stuff.
    ├── horus_gl                      # HorusGL folder.
    |    ├── assets                   # Assets folder.
    |    ├── horus                    # HorusGL files.
    |    |   ├── core                 # Core functionalities folder.
    |    |   |   ├── logger.h         # Logger utils.
    |    |   |   └── logger.cpp       # Logger utils implementation.
    |    |   ├── imgui                # ImGui related.
    |    |   |   └── imgui_build.cpp  # Put ImGui on the compilation unit.
    |    |   └── horus.h              # Single header for HorusGL features.
    |    ├── hglpch.h                 # Pre-compiled header.
    |    ├── main.cpp                 # HorusGL entrypoint.
    |    └── CMakeLists.txt           # HorusGL CMake build script.
    ├── vendor                        # Third-party packages will be here.
    |    ├── spdlog                   # Fast C++ logging library.
    |    ├── glfw                     # Library for window and input.
    |    ├── glad                     # OpenGL extension loader.
    |    ├── glm                      # OpenGL Mathematics.
    |    ├── imgui                    # Bloat-free Graphical User interface.
    |    └── stb_image                # Public domain image loader.
    └── CMakeLists.txt                # Main CMake build script.
```
 ## Compatibility

 | Toolset | Windows |  Linux  |   MacOS    |
 | :-----: | :-----: | :-----: | :--------: |
 |   GCC   |    ❔    |    ❔    |    ❔    |
 |  Clang   |    ✔️    |    ❔    |    ❔    |
 |  MSVC   |    ✔️    | ------- | ---------- |

<!-- Links -->
[cmake-url]: https://cmake.org/
[spdlog-url]: https://github.com/gabime/spdlog
[glfw-url]: https://github.com/glfw/glfw
[glad-url]: https://github.com/Dav1dde/glad
[glm-url]: https://github.com/g-truc/glm
[imgui-url]: https://github.com/ocornut/imgui
[stb_image-url]: https://github.com/

<!-- Badges -->
<!-- [build-status-badge]: https://github.com/thiago-rezende/horus-gl/workflows/build/badge.svg -->
[license-badge]: https://img.shields.io/badge/license-MIT-blue.svg?style=flat-square
[cmake-badge]: https://img.shields.io/badge/CMake-3.16.0-blueviolet.svg?style=flat-square
[cpp-badge]: https://img.shields.io/badge/C++-17-orange.svg?style=flat-square
