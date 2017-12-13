#pragma once

#include "t3Player.h"

class t3AI : public t3Player
{
public:

    t3AI(t3Piece piece);
    ~t3AI();

    bool Move(t3Board& board) override;

private:

    int _MiniMax(t3Board board, int row, int col, bool myTurn = false, int moves = 0);

};
