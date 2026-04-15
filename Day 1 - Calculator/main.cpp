#include <iostream>

int main(){
    std::cout << "Calculator\nChoose Operation (1-4)" << std::endl;
    int choice;
    std::cout << "1. Add\n2. Subtract\n3. Multiply\n4. Divide\n>> ";
    std::cin >> choice;
    while(true){
        if(choice < 1 || choice > 4){
            std::cout << "Invlaid choice, choose 1-4: ";
            std::cin >> choice;
        }else{
            break;
        }
    }
    float num1, num2;
    std::cout << "Enter two numbers: ";
    std::cin >> num1 >> num2;
    switch(choice){
        case 1:
            std::cout << num1+num2 << std::endl;
            break;
        case 2:
            std::cout << num1-num2 << std::endl;
            break;
        case 3:
            std::cout << num1*num2 << std::endl;
            break;
        case 4:
            std::cout << num1/num2 << std::endl;
            break;
    }
    std::cout << "Thanks for using!" << std::endl;
    return 0;
}