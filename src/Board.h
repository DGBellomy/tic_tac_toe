#ifndef Board_H
#define Board_H

#include "IRenderer.h"

class Board {
public:
    Board(IRenderer* board_renderer, IRenderer** piece_renderer);
    ~Board();

public:
    //bool Place(Piece value, int row, int col);
    //Piece GetPiece(int row, int col) const;
    //Status Status() const;
    //Piece ConvertToPiece(const char& piece) const;
    void Init();
    void Draw();

private:
    //Piece* m_Board;
    IRenderer* m_BoardRenderer;
    IRenderer** m_PieceRenderer;

};

#endif // Board_H
