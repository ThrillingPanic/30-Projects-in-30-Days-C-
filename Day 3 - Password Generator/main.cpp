#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
#include <fstream>

int main()
{
    std::string characterList = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*";
    std::srand(std::time(0));
    std::string password = "";
    int passwordLength;
    std::cout << "Password Generator\nEnter desired password length (minimum 8 chararacters, max 40): ";
    std::cin >> passwordLength;
    while (passwordLength < 8 || passwordLength > 40)
    {
        std::cout << "Invalid password length, enter a number between 8 and 40: ";
        std::cin >> passwordLength;
    }
    for (int i = 0; i < passwordLength; i++)
    {
        int randomIndex = std::rand() % characterList.length();
        password += characterList[randomIndex];
    }
    std::ofstream outputFile("password.txt", std::ios::app);
    if(outputFile.is_open()){
        std::cout << "Writing password to password.txt..." << std::endl;
        outputFile << password;
        outputFile.close();
    }
    else{
        std::cout << "Error writing to file!" << std::endl;
    }

    std::cout << "password.txt contains your new password!" << std::endl;

    return 0;
}