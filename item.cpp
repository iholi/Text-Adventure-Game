#include "item.h"

Item::Item() 
{
    name = " ";
}

Item::Item(std::string nameIn) 
{
    name = nameIn;
}

std::string Item::getName() const 
{
    return name;
}
