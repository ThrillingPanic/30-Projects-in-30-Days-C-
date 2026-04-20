#include <iostream>
#include <cstdlib>
#include <ctime>
#include <thread>

struct Dice{
    int sides, value;

    Dice(int sides){
        this->sides = sides;
    }

    void roll(){
        this->value = std::rand() % sides + 1;
    }
    
};

int main(){
    bool running = true;
    float balance = 1000;
    float bet = 0;
    char choice;
    int playerResult = 0;
    int cpuResult = 0;

    std::srand(std::time(0));

    Dice dice1(6);
    Dice dice2(6);
    
    std::cout << "Welcome to Donsters Dice Game!\nStarting balance is 1000 chips." << std::endl;
    while(running){
        std::cout << "Press R to roll, Q to quit and B for balance.\n>> ";
        std::cin >> choice;
        while(choice != 'R' && choice != 'Q' && choice != 'B'){
            std::cout << "Invalid choice, pick R, Q, or B.\n>> ";
            std::cin >> choice;
        }
        if(choice == 'R'){
            std::cout << "Enter bet: ";
            std::cin >> bet;
            while(bet < 0 || bet > balance){
                std::cout << "Invalid bet amount. You have " << balance << " chips." << std::endl;
                std::cout << "Enter bet: ";
                std::cin >> bet;
            }
            dice1.roll();
            dice2.roll();
            playerResult = dice1.value + dice2.value;
            std::cout << "You rolled a... " << playerResult << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(1));

            dice1.roll();
            dice2.roll();
            cpuResult = dice1.value + dice2.value;
            std::cout << "Computer rolled a... " << cpuResult << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(1));

            if(playerResult > cpuResult){
                balance += bet;
                std::cout << "You win!" << std::endl;
            }else if(playerResult < cpuResult){
                balance -= bet;
                std::cout << "You lose!" << std::endl;
            }else{
                std::cout << "The game is a tie!" << std::endl;
            }
            std::this_thread::sleep_for(std::chrono::seconds(1));
            std::cout << "New balance: " << balance << std::endl;
        }else if(choice == 'Q'){
            running = false;
            break;
        }else{
            std::cout << "Current balance: " << balance << std::endl;
        }
        if(balance == 0){
            running = false;
            std::cout << "You have 0 chips remaining, game over!" << std::endl;
        }
    }
    std::cout << "Thank you for playing!" << std::endl;

    return 0;
}