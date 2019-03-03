#ifndef LIST_H
#define LIST_H
#include <string>
#include <iostream>
#include "item.h"

class List 
{

private:
    int arraySize;
    Item itemsArray[6];
        
public:
    List();
    void addItem(Item add);
    void display() const;
    bool inPocket(std::string) const;

};

#endif
