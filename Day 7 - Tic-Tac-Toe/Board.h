#pragma once

class Board
{
public:
    char gameBoard[3][3]; 
    void print();
    bool checkWin(char player);
    Board();
};