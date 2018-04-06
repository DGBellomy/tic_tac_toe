#include "Board.h"

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// CONSTRUCTORS & DECONSTRUCTOR
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

Board::Board(IRenderer* board_renderer)
    : m_BoardRenderer(board_renderer)
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

Board::~Board()
{
    if (m_BoardRenderer != nullptr)
        delete m_BoardRenderer;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// PUBLIC METHODS
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

void Board::Init()
{
    m_BoardRenderer->Init();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

void Board::Draw()
{
    m_BoardRenderer->Draw();

    /*
     * for piece in m_Board:
     *   piece->Draw();
     */
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
