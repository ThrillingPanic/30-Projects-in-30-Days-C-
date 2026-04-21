#include "List.cpp"
#include <iostream>

int main()
{
    int choice;
    std::cout << "Welcome to Donsters To-Do list editor!" << std::endl;
    std::cout << "[1] Create new list\n[2] Load list\n>> ";
    std::cin >> choice;
    while (choice != 1 && choice != 2)
    {
        std::cout << "[1] Create new list\n[2] Load list\n>> ";
        std::cin >> choice;
    }
    std::string listName;
    std::cout << "Enter list name (excluding extension).\n>> ";
    std::getline(std::cin >> std::ws, listName);
    std::cin.clear();
    List myList(listName);
    switch (choice)
    {
    case 1:
    {
        std::cout << "New list created!" << std::endl;
        break;
    }
    case 2:
    {
        if(myList.load(listName) == 1){
            std::cout << "List loaded!\n" << std::endl;
            myList.print();
        }else{
            std::cout << "File could not be found, creating new list." << std::endl;
        }
        break;
    }
    }
    std::cout << "What would you like to do?" << std::endl;
    bool running = true;
    while (running)
    {
        std::cout << "[1] Add item\n[2] Delete item\n[3] Print contents\n[4] Save File\n[5] Quit\n>> ";
        std::cin >> choice;
        while (choice < 1 || choice > 5)
        {
            std::cout << "[1] Add item\n[2] Delete item\n[3] Print contents\n[4] Save File\n[5] Quit\n>> ";
            std::cin >> choice;
        }
        switch (choice)
        {
        case 1:
        {
            std::string content;
            std::cout << "Enter item to add\n>> ";
            std::cin >> content;
            myList.add(content);
            break;
        }
        case 2:
        {
            myList.print();
            std::cout << "Which line do you want to delete?\n>> ";
            std::cin >> choice;
            while (choice < 1 || choice > myList.listSize())
            {
                myList.print();
                std::cout << "Which line do you want to delete?\n>> ";
                std::cin >> choice;
            }
            myList.remove(choice);
            break;
        }
        case 3:
        {
            myList.print();
            break;
        }
        case 4:
        {
            if(myList.save() == 1){
                std::cout << "File saved!" << std::endl;
            }
            break;
        }
        case 5:
        {
            myList.save();
            running = false;
            break;
        }
        }
    }
    std::cout << "Thank you for using!" << std::endl;
    return 0;
}
