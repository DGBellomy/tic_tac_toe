#pragma once

#include "Board.h"
#include "Player.h"

namespace t3
{
    class Game
    {
    public:
        Game(Board* board, Player* player1, Player* player2);
        ~Game();

        Game(const Game& rhs) = delete;
        const Game& operator=(const Game& rhs) = delete;

    public:
        void Update();
        bool IsOver();

    private:
        Board* m_Board;
        Player* m_PlayerX;
        Player* m_PlayerO;
        Player* m_CurrentPlayer;

    };
};
