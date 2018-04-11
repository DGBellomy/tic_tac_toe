#include "OpenGLApp.h"
#include "TicTacToe.h"
#include "Board.h"
#include "GLT3BoardRenderer.h"
#include "GLT3PieceRenderer.h"

int main() {
    IRenderer** pieces;
    pieces = new IRenderer*[9];
    for (int i = 0; i < 9; ++i) {
        pieces[i] = new GLT3PieceRenderer();
    }

    OpenGLApp* app = new OpenGLApp(
            new TicTacToe(new Board(new GLT3BoardRenderer(), pieces)));

    if (app->Init())
        app->Run();

    return 0;
}
