#include <iostream>
#include "t3/Board.h"
#include "t3/Game.h"
#include "t3/Human.h"
#include "t3/AI.h"

t3::Board::Piece PickPiece()
{
    char choice;
    std::cout << "Pick (X/O): ";
    std::cin >> choice;

    switch (choice)
    {
    case 'X':
    case 'x':
        return t3::Board::Piece::X;
    case 'O':
    case 'o':
        return t3::Board::Piece::O;
    default:
        return t3::Board::Piece::ERROR;
    }
}

int main()
{
    t3::Game* game;

    unsigned short int num_players;
    do
    {
        std::cout << "How many players? ";
        std::cin >> num_players;
        std::cout << std::endl;
    } while (num_players < 0 || 2 < num_players);

    t3::Board::Piece piece;
    if (num_players == 1)
    {
        piece = PickPiece();
        while (piece == t3::Board::Piece::ERROR)
        {
            std::cout << "Invalid choice" << std::endl;
            piece = PickPiece();
        }
    }

    game = new t3::Game();

    if (!game->Init(num_players, piece))
        return 1;

    game->Start();
    while (!game->IsOver())
    {
        game->Update();
    }

    system("clear");
    std::cout << "***TIC-TAC-TOE***" << std::endl;
    switch(game->Winner())
    {
        case t3::Board::Status::X_WIN:
            std::cout << "X WINS THE GAME" << std::endl;
            break;
        case t3::Board::Status::O_WIN:
            std::cout << "O WINS THE GAME" << std::endl;
            break;
        case t3::Board::Status::TIE:
            std::cout << "NO ONE WINS THE GAME" << std::endl;
            break;
        default:
            break;
    }

    system("pause");
    return 0;
}
