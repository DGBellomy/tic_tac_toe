#pragma once

#include "Board.h"
#include "Player.h"

namespace t3
{
    class Game
    {
    public:
        Game();
        ~Game();

        Game(const Game& rhs) = delete;
        const Game& operator=(const Game& rhs) = delete;

    public:
        bool Init(int num_players, Board::Piece piece);
        void Start();
        void Update();
        bool IsOver();
        Board::Status Winner();

    private:
        Board* m_Board;
        Player* m_PlayerX;
        Player* m_PlayerO;
        Player* m_CurrentPlayer;

    };
};
