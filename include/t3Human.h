#pragma once

#include "t3Player.h"

class t3Human : public t3Player
{
public:

    t3Human(t3Piece piece);
    ~t3Human();

    bool Move(t3Board& board) override;

private:

    void _DisplayBoard(const t3Board& board) const;
};
