#ifndef T3_BOARD_H
#define T3_BOARD_H

#include <vector>

enum t3Piece {EMPTY, X, O, ERROR};
enum t3Status {IN_PROGRESS, X_WIN, O_WIN, TIE};

class t3Board
{
public:

    t3Board();
    ~t3Board();

    void Render() const;
    bool SetPiece(int row, int col, t3Piece value);
    t3Piece GetPiece(int row, int col) const;
    t3Status Status() const;

private:

    char _ConvertPiece(t3Piece piece) const;

private:

    std::vector<t3Piece> m_board;

};

#endif // T3_BOARD_H
