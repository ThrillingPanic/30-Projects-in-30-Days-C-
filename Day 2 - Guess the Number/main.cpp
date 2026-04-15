#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

int main()
{
    std::srand(std::time(0));
    int randomNumber = std::rand() % 100 + 1;
    int numGuesses = 0;
    int guess = -1;
    std::cout << "Number Guessing Game\nYou will try to guess the randomly picked number 1-100, try to get the lowest score." << std::endl;
    std::cout << "Enter guess: ";
    std::cin >> guess;
    while (guess != randomNumber)
    {
        std::cout << "Wrong number!" << std::endl;
        if (guess < randomNumber)
        {
            std::cout << "Guess is too low." << std::endl;
        }
        else
        {
            std::cout << "Guess is too high." << std::endl;
        }
        std::cout << "Enter guess: ";
        std::cin >> guess;
        numGuesses++;
    }
std::cout << "You have guessed the correct number!" << std::endl;
std::cout << "Score: " << numGuesses << std::endl;

return 0;
}