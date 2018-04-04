#ifndef OpenGLApp_H
#define OpenGLApp_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class OpenGLApp {

public:
    OpenGLApp();
    ~OpenGLApp();

    OpenGLApp(const OpenGLApp& rhs) = delete;
    OpenGLApp& operator=(const OpenGLApp& rhs) = delete;

public:
    bool Init();
    void Run();

private:
    GLFWwindow* m_WindowPtr;

};

#endif // OpenGLApp_H
