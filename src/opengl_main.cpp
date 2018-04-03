#include <iostream>
#include <sstream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>


GLFWwindow* g_WindowPtr = nullptr;

void GLFW_OnKey(GLFWwindow* window, int key, int scancode, int action, int mode) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
}

bool InitOpenGL() {
    // Init OpenGL
    if (!glfwInit()) {
        std::cerr << "GLFW Failed to Init." << std::endl;
        return false;
    }

    // Configure Window
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    // Create Window
    g_WindowPtr = glfwCreateWindow(800, 600, "TACOS RULE", NULL, NULL);

    if (g_WindowPtr == nullptr) {
        std::cerr << "Failed to create GLFW Window Ptr." << std::endl;
        glfwTerminate();
        return false;
    }

    // Make Current Window
    glfwMakeContextCurrent(g_WindowPtr);

    // Set Keyboard Input
    glfwSetKeyCallback(g_WindowPtr, GLFW_OnKey);

    // Set Mouse Input
    glfwSetInputMode(g_WindowPtr, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwSetCursorPos(g_WindowPtr, 800 / 2.0, 600 / 2.0);

    // Init glad
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to Init GLAD." << std::endl;
        return false;
    }

    // Set Clear Color
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.23f, 0.38f, 0.47f, 1.0f);

    return true;
}

int main() {
    // Init OpenGL
    if (!InitOpenGL()) {
        std::cerr << "OpenGL Failed to Init." << std::endl;
        return -1;
    }

    // Game Loop
    while (!glfwWindowShouldClose(g_WindowPtr)) {
        glfwPollEvents();

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glfwSwapBuffers(g_WindowPtr);
    }

    glfwTerminate();
    return 0;
}
