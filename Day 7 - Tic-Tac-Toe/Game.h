#pragma once
#include "Board.h"

class Game{
    private:
        Board board;
        char currentPlayer;
    public:
        void run();
        void switchTurn(char& player);
};