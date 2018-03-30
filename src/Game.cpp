#include "t3/Game.h"


namespace t3
{
    Game::Game(Board* board, Player* player1, Player* player2)
        : m_Board(board), m_PlayerX(player1), m_PlayerO(player2), m_CurrentPlayer(player1)
    {}

    Game::~Game()
    {
        if (m_PlayerO != nullptr)
            delete m_PlayerO;
        if (m_PlayerX != nullptr)
            delete m_PlayerX;
        if (m_Board != nullptr)
            delete m_Board;
    }

    void Game::Update()
    {
        if(m_CurrentPlayer->Move(m_Board))
            m_CurrentPlayer = (m_CurrentPlayer->GetPiece() == Board::Piece::X) ? m_PlayerO : m_PlayerX;
    }

    bool Game::IsOver()
    {
        return m_Board->GetStatus() == Board::Status::IN_PROGRESS;
    }

};
