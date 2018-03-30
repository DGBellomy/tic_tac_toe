#include "t3/AI.h"

#include <iostream>

#include "t3/Board.h"


namespace t3
{
    AI::AI(Board::Piece piece)
        :Player(piece)
    {
    }


    AI::~AI() {
    }

    bool AI::Move(Board & board)
    {
        int row, col;

        // find best move
        {
            int best_move = -12;
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (board.GetPiece(i, j) == Board::EMPTY)
                    {
                        int curr_move = _MiniMax(board, i, j);
                        if (curr_move > best_move)
                        {
                            row = i;
                            col = j;
                            best_move = curr_move;
                        }
                    }
                }
            }
        }

        return MakeMove(board, row, col);
    }

    int AI::_MiniMax(Board board, int row, int col, bool myTurn, int moves)
    {
        board.SetPiece(row, col, (myTurn) ?
                ((m_piece == Board::Piece::X) ?  Board::O : Board::Piece::X)
                : m_piece);
        Board::Status status = board.GetStatus();
        int best_move = (myTurn) ? -12 : 12;
        int move_value = 10 - moves;

        switch(status)
        {
            case Board::Status::IN_PROGRESS:
                for (int i = 0; i < 3; i++)
                    for (int j = 0; j < 3; j++)
                        if (board.GetPiece(i, j) == Board::Piece::EMPTY)
                        {
                            int curr_move = _MiniMax(board, i, j, !myTurn, moves + 1);
                            bool isBetterMove = (myTurn) ? (curr_move > best_move) : (curr_move < best_move);
                            if (isBetterMove)
                                best_move = curr_move;
                        }
                return best_move;
            case Board::Status::X_WIN:
                return move_value * ((m_piece == Board::Piece::X) ? 1 : -1);
            case Board::Status::O_WIN:
                return move_value * ((m_piece == Board::Piece::O) ? 1 : -1);
            default:
                return 0;
        }
    }
};
