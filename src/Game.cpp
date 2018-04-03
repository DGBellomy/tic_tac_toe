#include "t3/Game.h"

#include "t3/Board.h"
#include "t3/Player.h"
#include "t3/AI.h"
#include "t3/Human.h"


namespace t3
{
    Game::Game()
        : m_Board(new Board()), m_PlayerX(nullptr), m_PlayerO(nullptr), m_CurrentPlayer(nullptr)
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

    bool Game::Init(int num_players, Board::Piece piece)
    {
        if (num_players == 0)
        {
            m_PlayerX = new AI(Board::Piece::X);
            m_PlayerO = new AI(Board::Piece::O);
            return true;
        }
        else if (num_players == 1)
        {
            if (piece == Board::Piece::X)
            {
                m_PlayerX = new Human(Board::Piece::X);
                m_PlayerO = new AI(Board::Piece::O);
                return true;
            }
            else if (piece == Board::Piece::O)
            {
                m_PlayerX = new AI(Board::Piece::X);
                m_PlayerO = new Human(Board::Piece::O);
                return true;
            }
        }
        else if (num_players == 2)
        {
            m_PlayerX = new Human(Board::Piece::X);
            m_PlayerO = new Human(Board::Piece::O);
            return true;
        }

        return false;
    }

    void Game::Start()
    {
        m_CurrentPlayer = m_PlayerX;
    }

    void Game::Update()
    {
        if(m_CurrentPlayer->Move(m_Board))
            m_CurrentPlayer = (m_CurrentPlayer->GetPiece() == Board::Piece::X) ? m_PlayerO : m_PlayerX;
    }

    bool Game::IsOver()
    {
        return m_Board->GetStatus() != Board::Status::IN_PROGRESS;
    }

    Board::Status Game::Winner()
    {
        m_Board->Render();
        return m_Board->GetStatus();
    }

};
