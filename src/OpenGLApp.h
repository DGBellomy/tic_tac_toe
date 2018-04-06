#ifndef OpenGLApp_H
#define OpenGLApp_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "IGame.h"

class OpenGLApp {

public:
    OpenGLApp(IGame* game);
    ~OpenGLApp();

    OpenGLApp(const OpenGLApp& rhs) = delete;
    OpenGLApp& operator=(const OpenGLApp& rhs) = delete;

public:
    bool Init();
    void Run();

private:
    bool _InitOpenGL();

private:
    GLFWwindow* m_WindowPtr;
    unsigned int m_ScreenWidth;
    unsigned int m_ScreenHeight;
    IGame* m_Game;

};

#endif // OpenGLApp_H
