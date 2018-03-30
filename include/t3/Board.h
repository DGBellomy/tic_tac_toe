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

        private:

            char _ConvertPiece(Piece piece) const;

        private:

            std::vector<Piece> m_board;

    };
};
