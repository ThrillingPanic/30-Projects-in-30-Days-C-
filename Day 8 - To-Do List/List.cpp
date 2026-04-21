#include "List.h"
#include <fstream>
#include <iostream>

void List::add(std::string contents)
{
    this->listItems.push_back(contents);
}

void List::print()
{
    for (u_long i = 0; i < this->listItems.size(); i++)
    {
        std::cout << i + 1 << ". " << listItems[i] << std::endl;
    }
}

void List::remove(int line)
{
    this->listItems.erase(this->listItems.begin() + line - 1);
}

bool List::save()
{
    std::ofstream outFile(this->name + ".txt");
    if (outFile.is_open())
    {
        for (u_long i = 0; i < this->listItems.size(); i++)
        {
            outFile << this->listItems[i] << std::endl;
        }
        outFile.close();
        return 1;
    }
    else
    {
        std::cout << "Error saving file!" << std::endl;
        return 0;
    }
}

List::List(std::string name)
{
    this->name = name;
}

bool List::load(std::string fileName)
{
    fileName += ".txt";
    std::ifstream inFile(fileName);
    if (inFile.is_open())
    {
        std::string s;
        while (getline(inFile, s))
        {
            this->listItems.push_back(s);
        }
        inFile.close();
        return 1;
    }
    else
    {
        std::cout << "Error opening file!" << std::endl;
        return 0;
    }
}

int List::listSize()
{
    return this->listItems.size();
}
