#include "Board.h"

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
        m_PieceRenderer[i]->Hide(true);

    m_BoardRenderer->Init(0.0f, 0.0f, 600.0f, 600.0f);
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

void Board::Draw()
{
    // Rendered as if being loaded into a stack???
    for (int i = 0; i < 9; ++i) {
        if ((i % 2) != 0) m_PieceRenderer[i]->Draw();
    }
    m_BoardRenderer->Draw();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
