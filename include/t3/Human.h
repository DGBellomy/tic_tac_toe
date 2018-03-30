#pragma once

#include "Board.h"
#include "Player.h"

namespace t3
{
    class Human : public Player
    {
        public:

            Human(Board::Piece piece);
            ~Human();

            bool Move(Board* board) override;

        private:

            void _DisplayBoard(const Board* board) const;
    };
};
