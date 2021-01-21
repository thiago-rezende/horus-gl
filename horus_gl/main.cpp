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

    /* GLFW window hints */
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);

    /* Create a windowed mode window and its OpenGL context */
    H_DEBUG("[GLFW] Creating window");
    window = glfwCreateWindow(800, 600, "HorusGL - OpenGL Starter Project", nullptr, nullptr);
    if (!window)
    {
        H_ERROR("[GLFW] Failed on window creation");

        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    H_DEBUG("[GLFW] Creating OpenGL context");
    glfwMakeContextCurrent(window);

    /* Loading OpenGL extensions */
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        H_ERROR("[GLAD] Failed on initialization");
        return 1;
    }

    /* Log OpenGL info */
    H_INFO("OpenGL Info:");
    H_INFO("| Vendor: {}", glGetString(GL_VENDOR));
    H_INFO("| Renderer: {}", glGetString(GL_RENDERER));
    H_INFO("| Version: {}", glGetString(GL_VERSION));

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
