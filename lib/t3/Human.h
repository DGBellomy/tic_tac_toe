#pragma once

#include "t3/Player.h"

class t3Human : public t3Player
{
public: // Constructors & Deconstructor

    t3Human(t3Piece piece) : t3Player(piece) {}
    ~t3Human() {}

public: // Methods

    bool Move(t3Board& board) override
    {
        int row, col;
        _DisplayBoard(board);
        std::cout << "Enter position (row col) here: ";
        std::cin >> row >> col;
        return MakeMove(board, row, col);
    }

private: // Methods

    void _DisplayBoard(const t3Board& board) const
    {
        std::cout << "***TIC-TAC-TOE***" << std::endl;
        std::cout << "Player" << m_piece << "'s turn" << std::endl;
        board.Render();
    }
};
