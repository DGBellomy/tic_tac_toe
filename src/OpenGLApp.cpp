#include "OpenGLApp.h"

#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "IGame.h"

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// KEYBOARD INPUT HANDLER
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

void GLFW_OnKey(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// CONSTRUCTORS & DECONSTRUCTOR
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

OpenGLApp::OpenGLApp(IGame* game)
    : m_WindowPtr(nullptr),
      m_ScreenWidth(800),
      m_ScreenHeight(600),
      m_Game(game)
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

OpenGLApp::~OpenGLApp()
{
    delete m_Game;
    glfwTerminate();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// PUBLIC METHODS
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

bool OpenGLApp::Init()
{
    // Init OpenGL
    if (!_InitOpenGL()) {
        std::cerr << "OpenGL Failed to Init." << std::endl;
        return false;
    }

    // Init Game
    m_Game->Init();

    return true;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

void OpenGLApp::Run()
{
    // Game Loop
    m_Game->Start();
    while (!glfwWindowShouldClose(m_WindowPtr)) {
        glfwPollEvents();
        m_Game->Update();

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        m_Game->Draw();

        glfwSwapBuffers(m_WindowPtr);
    }
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// PRIVATE METHODS
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

bool OpenGLApp::_InitOpenGL()
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
    m_WindowPtr = glfwCreateWindow(m_ScreenWidth, m_ScreenHeight,
                                   "TACOS RULE", NULL, NULL);

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
    glfwSetCursorPos(m_WindowPtr, m_ScreenWidth / 2.0, m_ScreenHeight / 2.0);

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

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
