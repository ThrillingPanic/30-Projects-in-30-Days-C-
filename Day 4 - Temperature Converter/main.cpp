#include <iostream>
#include <iomanip>

int main(){
    char startingUnit, endingUnit;

    std::cout << "Temperature Conversion" << std::endl;
    std::cout << "Avaliable units: Fahrenheit, Celsius, Kelvin" << std::endl;
    std::cout << "What temperature are you converting from (F, C, K)?\n>> ";
    
    std::cin >> startingUnit;

    while(startingUnit != 'F' && startingUnit != 'C' && startingUnit != 'K'){
        std::cout << "Invalid starting unit, please pick F, C, or K\n>> ";
        std::cin >> startingUnit;
    }

    std::cout << "What temperature are you converting to (F, C, K)?\n>> ";
    std::cin >> endingUnit;

    while(endingUnit != 'F' && endingUnit != 'C' && endingUnit != 'K'){
        std::cout << "Invalid ending unit, please pick F, C, or K\n>> ";
        std::cin >> endingUnit;
    }

    float tempInput, convertedTemp;
    std::cout << "Enter temperature (" << startingUnit << "):\n>> ";
    std::cin >> tempInput;

    if(startingUnit == 'F'){
        if(endingUnit == 'C'){
            convertedTemp = (tempInput - 32) * 5/9;
        }else if(endingUnit == 'K'){
            convertedTemp = (tempInput - 32) * 5/9 + 273.15;
        }else{
            convertedTemp = tempInput;
        }
    }else if(startingUnit == 'C'){
        if(endingUnit == 'F'){
            convertedTemp = (tempInput * 9/5) + 32;
        }else if(endingUnit == 'K'){
            convertedTemp = tempInput = 273.15;
        }else{
            convertedTemp = tempInput;
        }
    }else{
        if(endingUnit == 'F'){
            convertedTemp = (tempInput - 273.15) * 9/5 + 32;
        }else if(endingUnit == 'C'){
            convertedTemp = tempInput - 273.15;
        }else{
            convertedTemp = tempInput;
        }
    }
    std::cout << tempInput << startingUnit << " is " 
    << std::fixed << std::setprecision(2) << convertedTemp 
    << endingUnit << std::endl;
    
    return 0;
}