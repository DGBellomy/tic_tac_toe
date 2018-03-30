#pragma once

#include <vector>

namespace t3
{
    class Board
    {
        public:
            enum Piece {EMPTY, X, O, ERROR};
            enum Status {IN_PROGRESS, X_WIN, O_WIN, TIE};

        public:

            Board();
            ~Board();

            void Render() const;
            bool SetPiece(int row, int col, Piece value);
            Piece GetPiece(int row, int col) const;
            Status GetStatus() const;
            Piece ConvertToPiece(const char& piece) const;

        private:

            char _ConvertToChar(Piece piece) const;

        private:

            std::vector<Piece> m_board;

    };
};
