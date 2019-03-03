#ifndef ITEM_H
#define ITEM_H
#include <string>
#include <iostream>

class Item 
{
private:
    std::string name;

public:
    Item();
    Item(std::string);
    std::string getName() const;

};
#endif
