#include "t3Human.h"
#include <iostream>



t3Human::t3Human(t3Piece piece)
    :t3Player(piece)
{
}


t3Human::~t3Human()
{
}

bool t3Human::Move(t3Board & board)
{
    int row, col;
    _DisplayBoard(board);
    std::cout << "Enter position (row col) here: ";
    std::cin >> row >> col;
    return MakeMove(board, row, col);
}

void t3Human::_DisplayBoard(const t3Board & board) const
{
    std::cout << "***TIC-TAC-TOE***" << std::endl;
    std::cout << "Player" << m_piece << "'s turn" << std::endl;
    board.Render();
}
