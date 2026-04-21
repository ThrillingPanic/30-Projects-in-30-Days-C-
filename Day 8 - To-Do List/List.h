#pragma once

#include <iostream>
#include <string>
#include <vector>

class List{
    private:
        std::vector<std::string> listItems;
        std::string name;
    public:
        List(std::string name);
        void add(std::string content);
        void remove(int line);
        bool save();
        bool load(std::string fileName);
        void print();
        int listSize();
};