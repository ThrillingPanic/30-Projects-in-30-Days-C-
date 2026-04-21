#include "Board.h"
#include <iostream>

void Board::print(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            std::cout << gameBoard[i][j];
            if(j != 2){
                std::cout << " | ";
            }else{
                std::cout << std::endl;
            }
        }
        if(i != 2){
            std::cout << "---------" << std::endl;
        } 
    }
}

Board::Board(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            gameBoard[i][j] = '-';
        }
    }
}

bool Board::checkWin(char player){
    for (int i = 0; i < 3; i++) {
        if (gameBoard[i][0] == player && gameBoard[i][1] == player && gameBoard[i][2] == player) {
            return true;
        }
    }

    for (int j = 0; j < 3; j++) {
        if (gameBoard[0][j] == player && gameBoard[1][j] == player && gameBoard[2][j] == player) {
            return true;
        }
    }

    if (gameBoard[0][0] == player && gameBoard[1][1] == player && gameBoard[2][2] == player) {
        return true;
    }

    if (gameBoard[0][2] == player && gameBoard[1][1] == player && gameBoard[2][0] == player) {
        return true;
    }

    return false;
}

