#include "list.h"

List::List() 
{
    arraySize = 6;
}

void List::addItem(Item add) 
{
    int count = 0;
    for (int i = 0; i < arraySize; i++) 
    {
        if (itemsArray[i].getName() == " " && count < 1) 
	{
            itemsArray[i] = add;
            std::cout << "Added " << itemsArray[i].getName() 
            << " to your pocket." << std::endl;
            count++;
        }
    }
}

void List::display() const 
{
    std::cout << "\nItems in your pocket (which only can hold "
            << "4 items)." << std::endl;
    for (int i = 0; i < arraySize; i++)
    {
        if (itemsArray[i].getName() != " ") 
	{
            std::cout << "Slot " << i << " Item: " 
                    << itemsArray[i].getName() << std::endl;
        }
        else if (itemsArray[i].getName() == " ") 
	{	
            std::cout << "Slot " << i << " empty." << std::endl;
        }
    }
}

bool List::inPocket(std::string nameIn) const 
{
    for (int i = 0; i < arraySize; i++)
    {
        if (itemsArray[i].getName() == nameIn)
            return true;
    }
    return false;
}
