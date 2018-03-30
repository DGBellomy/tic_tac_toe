#pragma once

#include "t3/Board.h"

class t3Player
{
public: // Constructors & Deconstructor

    t3Player(t3Piece piece) : m_piece(piece) {}
    ~t3Player() {}

public: // Methods

    virtual bool Move(t3Board& board) = 0;
    t3Piece GetPiece() const { return m_piece; }

protected: // Methods

    bool MakeMove(t3Board& board, int row, int col)
    {
        if (!board.SetPiece(row, col, m_piece))
            return false;
        return true;
    }

protected: // Attributes

    const t3Piece m_piece;
};
