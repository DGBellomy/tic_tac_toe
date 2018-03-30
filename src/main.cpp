#include <iostream>
#include "t3/Board.h"
#include "t3/Human.h"
#include "t3/AI.h"

t3::Board::Piece PickPiece();

int main()
{
    t3::Board board;
    t3::Player* player1 = nullptr;
    t3::Player* player2 = nullptr;
    t3::Player* current;

    // how many players?
    while (true)
    {
        int num_players;
        std::cout << "How many players? ";
        std::cin >> num_players;
        std::cout << std::endl;
        t3::Board::Piece piece;

        switch(num_players)
        {
        case 0:
            player1 = new t3::AI(t3::Board::Piece::X);
            player2 = new t3::AI(t3::Board::Piece::O);
            break;
        case 1:
            while ((piece = PickPiece()) == t3::Board::Piece::ERROR)
                std::cout << "Invalid choice" << std::endl;

            switch(piece)
            {
            case t3::Board::Piece::X:
                player1 = new t3::Human(t3::Board::Piece::X);
                player2 = new t3::AI(t3::Board::Piece::O);
                break;
            case t3::Board::Piece::O:
                player1 = new t3::AI(t3::Board::Piece::X);
                player2 = new t3::Human(t3::Board::Piece::O);
                break;
            default:
                std::cout << "ERROR: Invalid value for piece." << std::endl;
                continue;
            }
            break;
        case 2:
            player1 = new t3::Human(t3::Board::Piece::X);
            player2 = new t3::Human(t3::Board::Piece::O);
            break;
        default:
            std::cout << "Invalid number of players" << std::endl;
            continue;
        }

        break;
    }

    current = player1;

    while (board.GetStatus() == t3::Board::Status::IN_PROGRESS)
    {
        system("clear");
        while (!current->Move(board))
            std::cout << "invalid move" << std::endl;
        current = (current->GetPiece() == t3::Board::Piece::X) ? player2 : player1;
    }

    system("clear");
    std::cout << "***TIC-TAC-TOE***" << std::endl;
    board.Render();
    switch(board.GetStatus())
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
    return 0;
}

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
