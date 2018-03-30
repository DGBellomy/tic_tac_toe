#include "t3/Human.h"

#include <iostream>

#include "t3/Board.h"

namespace t3
{
    Human::Human(Board::Piece piece)
        :Player(piece)
    {
    }

    Human::~Human()
    {
    }

    bool Human::Move(Board* board)
    {
        int row, col;
        _DisplayBoard(board);
        std::cout << "Enter position (row col) here: ";
        std::cin >> row >> col;
        return MakeMove(board, row, col);
    }

    void Human::_DisplayBoard(const Board* board) const
    {
        std::cout << "***TIC-TAC-TOE***" << std::endl;
        std::cout << "Player" << m_piece << "'s turn" << std::endl;
        board->Render();
    }
};
