/* HorusGL */
#include <horus/horus.h>

/* CMake Configured File */
#include <config.h>

int main()
{
    /* Initialize Logger */
    Horus::Logger::Init();

    /* GLFW Window */
    GLFWwindow *window;

    /* Initialize the library */
    H_DEBUG("[GLFW] Initializing GLFW");
    if (!glfwInit())
    {
        H_ERROR("[GLFW] Failed on initialization");

        return -1;
    }

    /* Create a windowed mode window and its OpenGL context */
    H_DEBUG("[GLFW] Creating window");
    window = glfwCreateWindow(800, 600, "HorusGL", nullptr, nullptr);
    if (!window)
    {
        H_ERROR("[GLFW] Failed on window creation");

        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    H_DEBUG("[GLFW] Creating OpenGL context");
    glfwMakeContextCurrent(window);

    /* Loop until the user closes the window */
    H_INFO("Starting HorusGL");
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.25f, 0.25f, 0.25f, 1.0f);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    /* GLFW Termination */
    H_DEBUG("[GLFW] Terminating GLFW");
    glfwTerminate();

    H_INFO("Closing");
    return 0;
}
