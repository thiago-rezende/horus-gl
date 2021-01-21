/**
 * @file hglpch.h
 * @author Thiago Rezende (thiago-rezende.github.io)
 * @brief HorusGL pre-compiled header
 * @version 0.1
 * @date 2021-01-21
 *
 * @copyright Copyright (c) 2021 Thiago Rezende
 *
 */

#pragma once

/* Windows Things */
#ifdef WIN32

/* Exclude rarely-used services from Windows headers */
#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN
#endif // VC_EXTRALEAN

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif // WIN32_LEAN_AND_MEAN

/* Windows Header */
#include <Windows.h>

#endif // WIN32

/* StdLib Things */
#include <iostream>
#include <string>

/* GLAD */
#include <glad/glad.h>

/* GLFW */
#include <GLFW/glfw3.h>

/* GLM */
#include <glm/glm.hpp>

/* ImGui */
#include <imgui.h>
#include <backends/imgui_impl_opengl3.h>
#include <backends/imgui_impl_glfw.h>
