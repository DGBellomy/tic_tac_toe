#include "Board.h"

#include "InputHandler.h"

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// CONSTRUCTORS & DECONSTRUCTOR
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

Board::Board(IRenderer* board_renderer, IRenderer** piece_renderer)
    : m_BoardRenderer(board_renderer),
      m_PieceRenderer(piece_renderer)
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

Board::~Board()
{
    if (m_BoardRenderer != nullptr)
        delete m_BoardRenderer;
    if (m_PieceRenderer != nullptr) {
        for (int i = 0; i < 9; ++i) {
            delete m_PieceRenderer[i];
        }
        delete m_PieceRenderer;
    }
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// PUBLIC METHODS
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

void Board::Init()
{
    m_PieceRenderer[0]->Init(-200.0f, 200.0f, 100.0f, 100.0f);
    m_PieceRenderer[1]->Init(0.0f, 200.0f, 100.0f, 100.0f);
    m_PieceRenderer[2]->Init(200.0f, 200.0f, 100.0f, 100.0f);
    m_PieceRenderer[3]->Init(-200.0f, 0.0f, 100.0f, 100.0f);
    m_PieceRenderer[4]->Init(0.0f, 0.0f, 100.0f, 100.0f);
    m_PieceRenderer[5]->Init(200.0f, 0.0f, 100.0f, 100.0f);
    m_PieceRenderer[6]->Init(-200.0f, -200.0f, 100.0f, 100.0f);
    m_PieceRenderer[7]->Init(0.0f, -200.0f, 100.0f, 100.0f);
    m_PieceRenderer[8]->Init(200.0f, -200.0f, 100.0f, 100.0f);

    for (int i = 0; i < 9; ++i)
        m_PieceRenderer[i]->Hide();

    m_BoardRenderer->Init(0.0f, 0.0f, 600.0f, 600.0f);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

void Board::Draw()
{
    InputHandler* input_handler = InputHandler::GetInstance();

    if (input_handler->MouseDown()) {
        double x_pos = input_handler->MouseXPos() - 400.0;
        double y_pos = -1.0 * (input_handler->MouseYPos() - 300.0);
        int index = 0;

        if (-300.0 < y_pos && y_pos < -100.0) index = 6;
        else if (-100.0 < y_pos && y_pos < 100.0) index = 3;
        else if (100.0 < y_pos && y_pos < 300.0) index = 0;
        else index = -1;

        if (index >= 0) {
            if (-300.0 < x_pos && x_pos < -100.0) index += 0;
            else if (-100.0 < x_pos && x_pos < 100.0) index += 1;
            else if (100.0 < x_pos && x_pos < 300.0) index += 2;
            else index = -1;
        }

        if (index >= 0) m_PieceRenderer[index]->Hide(false);
    }

    // Rendered as if being loaded into a stack???
    for (int i = 0; i < 9; ++i) {
        m_PieceRenderer[i]->Draw();
    }
    m_BoardRenderer->Draw();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
