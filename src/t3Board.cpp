#include "t3Board.h"
#include <iostream>
#include <sstream>

t3Board::t3Board()
    :m_board(9)
{
}


t3Board::~t3Board()
{
}


void t3Board::Render() const
{
    std::ostringstream display(std::ostringstream::ate);

    std::string row_divider = "    ";
    for (int row = 0; row < 3; row++)
    {
        display << row_divider;

        std::string col_divider = "";
        for (int col = 0; col < 3; col++)
        {
            display << col_divider << _ConvertPiece(GetPiece(row, col));
            col_divider = "|";
        }
        row_divider = "\n    -----\n    ";
    }
    display << '\n';

    std::cout << display.str();
}


bool t3Board::SetPiece(int row, int col, t3Piece value)
{
    if (GetPiece(row, col) == EMPTY && row < 3 && col < 3)
    {
        m_board[row*3 + col] = value;
        return true;
    }

    return false;
}


t3Piece t3Board::GetPiece(int row, int col) const
{
    if (row < 3 && col < 3)
        return m_board[row * 3 + col];
    else
        return ERROR;
}


t3Status t3Board::Status() const
{
    t3Piece piece;

    if ((piece = GetPiece(1, 1)) != EMPTY)
    {
        if ((piece == GetPiece(0, 0) && piece == GetPiece(2, 2))
                || (piece == GetPiece(0, 2) && piece == GetPiece(2, 0))
                || (piece == GetPiece(0, 1) && piece == GetPiece(2, 1))
                || (piece == GetPiece(1, 0) && piece == GetPiece(1, 2)))
            return (piece == X)? X_WIN : O_WIN;
    }

    if ((piece = GetPiece(0, 0)) != EMPTY)
    {
        if ((piece == GetPiece(0, 1) && piece == GetPiece(0, 2))
                || (piece == GetPiece(1, 0) && piece == GetPiece(2, 0)))
            return (piece == X)? X_WIN : O_WIN;
    }

    if ((piece = GetPiece(2, 2)) != EMPTY)
    {
        if ((piece == GetPiece(1, 2) && piece == GetPiece(0, 2))
                || (piece == GetPiece(2, 0) && piece == GetPiece(2, 1)))
            return (piece == X)? X_WIN : O_WIN;
    }

    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (GetPiece(row, col) == EMPTY)
                return IN_PROGRESS;

    return TIE;
}


char t3Board::_ConvertPiece(t3Piece piece) const
{
    switch(piece)
    {
        case EMPTY:
            return ' ';
        case X:
            return 'X';
        case O:
            return 'O';
        default:
            return 'F';
    }
}
