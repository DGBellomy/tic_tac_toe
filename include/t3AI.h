#pragma once

#include "t3Player.h"

class t3AI : public t3Player
{
public: // Constructors & Deconstructor

    t3AI(t3Piece piece) : t3Player(piece) {}
    ~t3AI() {}

public: // Methods

    bool Move(t3Board& board) override
    {
        int row, col;

        // find best move
        {
            int best_move = -12;
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (board.GetPiece(i, j) == EMPTY)
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

private: // Methods

    int _MiniMax(t3Board board, int row, int col, bool myTurn = false, int moves = 0)
    {
        board.SetPiece(row, col, (myTurn) ? ((m_piece == X) ? O : X) : m_piece);
        t3Status status = board.Status();
        int best_move = (myTurn) ? -12 : 12;
        int move_value = 10 - moves;

        switch(status)
        {
        case IN_PROGRESS:
            for (int i = 0; i < 3; i++)
                for (int j = 0; j < 3; j++)
                    if (board.GetPiece(i, j) == EMPTY)
                    {
                        int curr_move = _MiniMax(board, i, j, !myTurn, moves + 1);
                        bool isBetterMove = (myTurn) ? (curr_move > best_move) : (curr_move < best_move);
                        if (isBetterMove)
                            best_move = curr_move;
                    }
            return best_move;
        case X_WIN:
            return move_value * ((m_piece == X) ? 1 : -1);
        case O_WIN:
            return move_value * ((m_piece == O) ? 1 : -1);
        default:
            return 0;
        }
    }

};
