#include "OpenGLApp.h"
#include "TicTacToe.h"
#include "Board.h"
#include "GLT3BoardRenderer.h"

int main() {
    OpenGLApp* app = new OpenGLApp(
            new TicTacToe(new Board(new GLT3BoardRenderer())));

    if (app->Init())
        app->Run();

    return 0;
}
