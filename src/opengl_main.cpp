#include "OpenGLApp.h"

int main() {
    OpenGLApp* app = new OpenGLApp();

    if (app->Init())
        app->Run();

    return 0;
}
