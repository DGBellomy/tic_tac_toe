#ifndef TicTacToe_H
#define TicTacToe_H

#include "IGame.h"
#include "Board.h"

class TicTacToe : public IGame {
public:
    TicTacToe(Board* board);
    ~TicTacToe() override;

    TicTacToe(const TicTacToe& rhs) = delete;
    TicTacToe& operator=(const TicTacToe& rhs) = delete;

public:
    void Init() override;
    void Start() override;
    void Update() override;
    void Draw() override;

private:
    // Question
    Board* m_Board;
    // PlayerX
    // PlayerO
    // CurrentPlayerPtr
};

#endif // TicTacToe_H
