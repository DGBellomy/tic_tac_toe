#pragma once

#include "t3Board.h"

class t3Player
{
public:

    t3Player(t3Piece piece);

    virtual bool Move(t3Board& board) = 0;
    t3Piece GetPiece() const;

protected:

    bool MakeMove(t3Board& board, int row, int col);

protected:

    const t3Piece m_piece;
};
