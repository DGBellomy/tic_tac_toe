#include "t3/Board.h"

#include <iostream>
#include <sstream>

namespace t3
{
    Board::Board()
        :m_board(9)
    {
    }


    Board::~Board()
    {
    }


    void Board::Render() const
    {
        std::ostringstream display(std::ostringstream::ate);

        std::string row_divider = "    ";
        for (int row = 0; row < 3; row++)
        {
            display << row_divider;

            std::string col_divider = "";
            for (int col = 0; col < 3; col++)
            {
                display << col_divider << _ConvertToChar(GetPiece(row, col));
                col_divider = "|";
            }
            row_divider = "\n    -----\n    ";
        }
        display << '\n';

        std::cout << display.str();
    }


    bool Board::SetPiece(int row, int col, Piece value)
    {
        if (GetPiece(row, col) == Piece::EMPTY && row < 3 && col < 3)
        {
            m_board[row*3 + col] = value;
            return true;
        }

        return false;
    }


    Board::Piece Board::GetPiece(int row, int col) const
    {
        if (row < 3 && col < 3)
            return m_board[row * 3 + col];
        else
            return Piece::ERROR;
    }


    Board::Status Board::GetStatus() const
    {
        Piece piece;

        if ((piece = GetPiece(1, 1)) != Piece::EMPTY)
        {
            if ((piece == GetPiece(0, 0) && piece == GetPiece(2, 2))
                    || (piece == GetPiece(0, 2) && piece == GetPiece(2, 0))
                    || (piece == GetPiece(0, 1) && piece == GetPiece(2, 1))
                    || (piece == GetPiece(1, 0) && piece == GetPiece(1, 2)))
                return (piece == Piece::X)? X_WIN : O_WIN;
        }

        if ((piece = GetPiece(0, 0)) != Piece::EMPTY)
        {
            if ((piece == GetPiece(0, 1) && piece == GetPiece(0, 2))
                    || (piece == GetPiece(1, 0) && piece == GetPiece(2, 0)))
                return (piece == Piece::X)? X_WIN : O_WIN;
        }

        if ((piece = GetPiece(2, 2)) != Piece::EMPTY)
        {
            if ((piece == GetPiece(1, 2) && piece == GetPiece(0, 2))
                    || (piece == GetPiece(2, 0) && piece == GetPiece(2, 1)))
                return (piece == Piece::X)? X_WIN : O_WIN;
        }

        for (int row = 0; row < 3; row++)
            for (int col = 0; col < 3; col++)
                if (GetPiece(row, col) == Piece::EMPTY)
                    return IN_PROGRESS;

        return TIE;
    }

    Board::Piece Board::ConvertToPiece(const char& piece) const
    {
        switch (piece)
        {
        case 'X':
        case 'x':
            return Piece::X;
        case 'O':
        case 'o':
            return Piece::O;
        default:
            return Piece::ERROR;
        }
    }


    char Board::_ConvertToChar(Board::Piece piece) const
    {
        switch(piece)
        {
            case Piece::EMPTY:
                return ' ';
            case Piece::X:
                return 'X';
            case Piece::O:
                return 'O';
            default:
                return 'F';
        }
    }
};
