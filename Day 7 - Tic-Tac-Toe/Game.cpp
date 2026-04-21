#include "Game.h"
#include "Board.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

void Game::run()
{
    Game game;
    std::cout << "Tic-Tac-Toe" << std::endl;
    std::cout << std::endl;
    while (!board.checkWin('X') && !board.checkWin('O'))
    {
        std::srand(std::time(0));
        board.print();
        std::cout << std::endl;
        currentPlayer = 'X';
        int row, column;
        std::cout << "Enter row (1-3) and column (1-3) to play\n>> ";
        std::cin >> row >> column;
        while (board.gameBoard[row - 1][column - 1] == 'X' || 
            board.gameBoard[row - 1][column - 1] == 'O' 
            && row < 1 || row > 3 || column < 1 || column > 3) //checks if valid placement
        {
            std::cout << "Invalid row/colunm input\n>> ";
            std::cin >> row >> column;
        }
        board.gameBoard[row - 1][column - 1] = currentPlayer;
        if(board.checkWin('X')){
            break;
        }
        board.print();
        std::cout << std::endl;
        game.switchTurn(currentPlayer);
        row = std::rand() % 3 + 1;
        column = std::rand() % 3 + 1;
        while (board.gameBoard[row - 1][column - 1] == 'X' || 
            board.gameBoard[row - 1][column - 1] == 'O')
        {
            row = std::rand() % 3 + 1;
            column = std::rand() % 3 + 1;
        }
        board.gameBoard[row - 1][column - 1] = currentPlayer;
    }
    std::cout << std::endl;
    board.print();
    std::cout << std::endl;
    std::cout << currentPlayer << " wins!" << std::endl;
}

void Game::switchTurn(char &player)
{
    if (player == 'X')
    {
        player = 'O';
    }
    else
    {
        player = 'X';
    }
}