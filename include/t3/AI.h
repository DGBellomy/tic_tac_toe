#pragma once

#include "Player.h"

namespace t3
{
    class AI : public Player
    {
        public:

            AI(Board::Piece piece);
            ~AI();

            bool Move(Board& board) override;

        private:

            int _MiniMax(Board board, int row, int col, bool myTurn = false, int moves = 0);

    };
};
