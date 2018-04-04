#include "OpenGLApp.h"

#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

void GLFW_OnKey(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
}


OpenGLApp::OpenGLApp()
    : m_WindowPtr(nullptr) {}

OpenGLApp::~OpenGLApp()
{
    glfwTerminate();
}

bool OpenGLApp::Init()
{
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
    m_WindowPtr = glfwCreateWindow(800, 600, "TACOS RULE", NULL, NULL);

    if (m_WindowPtr == nullptr) {
        std::cerr << "Failed to create GLFW Window Ptr." << std::endl;
        glfwTerminate();
        return false;
    }

    // Make Current Window
    glfwMakeContextCurrent(m_WindowPtr);

    // Set Keyboard Input
    glfwSetKeyCallback(m_WindowPtr, GLFW_OnKey);

    // Set Mouse Input
    glfwSetInputMode(m_WindowPtr, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    glfwSetCursorPos(m_WindowPtr, 800 / 2.0, 600 / 2.0);

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

void OpenGLApp::Run()
{
    // Game Loop
    while (!glfwWindowShouldClose(m_WindowPtr)) {
        glfwPollEvents();

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glfwSwapBuffers(m_WindowPtr);
    }
}
