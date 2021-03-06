#include "t3/Player.h"

#include "t3/Board.h"

namespace t3
{
    Player::Player(Board::Piece piece)
        : m_piece(piece)
    {}

    Board::Piece Player::GetPiece() const
    {
        return m_piece;
    }

    bool Player::MakeMove(Board & board, int row, int col)
    {
        if (!board.SetPiece(row, col, m_piece))
            return false;
        return true;
    }
};
