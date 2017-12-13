#include "t3Player.h"

t3Player::t3Player(t3Piece piece)
    :m_piece(piece)
{
}

t3Piece t3Player::GetPiece() const
{
    return m_piece;
}

bool t3Player::MakeMove(t3Board & board, int row, int col)
{
    if (!board.SetPiece(row, col, m_piece))
        return false;
    return true;
}
