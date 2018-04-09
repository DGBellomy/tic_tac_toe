#include "TicTacToe.h"

#include "Board.h"
#include "InputHandler.h"

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// CONSTRUCTORS & DECONSTRUCTOR
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

TicTacToe::TicTacToe(Board* board)
     : m_Board(board)
    // , m_PlayerX(), m_PlayerO(), m_CurrentPlayer()
{}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

TicTacToe::~TicTacToe()
{
    if (m_Board != nullptr)
        delete m_Board;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// IGAME INTERFACE METHODS
// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

void TicTacToe::Init()
{
    m_Board->Init();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

void TicTacToe::Start()
{
    // m_PlayerX = AI();
    // m_PlayerO = AI();
    // m_CurrentPlayer = m_PlayerX;
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

void TicTacToe::Update()
{
    // if (m_Board->Status() != IN_PROGRESS)
    //     m_GameOver = true;
    // else if (m_CurrentPlayer->Moved())
    //     m_CurrentPlayer = (m_CurrentPlayer == m_PlayerX) ? m_PlayerO : m_PlayerX;
    // else
    //     m_CurrentPlayer->Update();
}

/*
 * if (clicked position)
 *     moved = board->MakeMove(position.row, position.col);
 *     */

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

void TicTacToe::Draw()
{
    auto input_handler = InputHandler::GetInstance();
    if (input_handler->MouseDown()) {
        m_Board->Draw();
    }
    // m_Question->Draw();
    //m_Board->Draw();
}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
