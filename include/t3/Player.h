#pragma once

#include "Board.h"

namespace t3
{
    class Player
    {
        public:

            Player(Board::Piece piece);

            virtual bool Move(Board& board) = 0;
            Board::Piece GetPiece() const;

        protected:

            bool MakeMove(Board& board, int row, int col);

        protected:

            const Board::Piece m_piece;
    };
};
