#include <iostream>
#include "t3Board.h"
#include "t3Human.h"
#include "t3AI.h"

t3Piece PickPiece();

int main()
{
    t3Board board;
    t3Player* player1 = nullptr;
    t3Player* player2 = nullptr;
    t3Player* current;

    // how many players?
    while (true)
    {
        int num_players;
        std::cout << "How many players? ";
        std::cin >> num_players;
        std::cout << std::endl;
        t3Piece piece;

        switch(num_players)
        {
        case 0:
            player1 = new t3AI(X);
            player2 = new t3AI(O);
            break;
        case 1:
            while ((piece = PickPiece()) == ERROR)
                std::cout << "Invalid choice" << std::endl;

            switch(piece)
            {
            case X:
                player1 = new t3Human(X);
                player2 = new t3AI(O);
                break;
            case O:
                player1 = new t3AI(X);
                player2 = new t3Human(O);
            default:
                std::cout << "ERROR: Invalid value for piece" << std::endl;
                continue;
            }
            break;
        case 2:
            player1 = new t3Human(X);
            player2 = new t3Human(O);
            break;
        default:
            std::cout << "Invalid number of players" << std::endl;
            continue;
        }

        break;
    }

    current = player1;

    while (board.Status() == IN_PROGRESS)
    {
        system("clear");
        while (!current->Move(board))
            std::cout << "invalid move" << std::endl;
        current = (current->GetPiece() == X) ? player2 : player1;
    }

    system("clear");
    std::cout << "***TIC-TAC-TOE***" << std::endl;
    board.Render();
    switch(board.Status())
    {
        case X_WIN:
            std::cout << "X WINS THE GAME" << std::endl;
            break;
        case O_WIN:
            std::cout << "O WINS THE GAME" << std::endl;
            break;
        case TIE:
            std::cout << "NO ONE WINS THE GAME" << std::endl;
            break;
        default:
            break;
    }
    return 0;
}

t3Piece PickPiece()
{
    char choice;
    std::cout << "Pick (X/O): ";
    std::cin >> choice;

    switch (choice)
    {
    case 'X':
    case 'x':
        return X;
    case 'O':
    case 'o':
        return O;
    default:
        return ERROR;
    }
}
