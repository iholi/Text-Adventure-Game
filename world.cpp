#include "world.h"

House::House() 
{
	up = NULL;
	down = NULL;
	right = NULL;
	left = NULL;
	actionComplete = false;
}

House::~House() {}

void House::setUp(House *houseP) 
{
	up = houseP;
}

void House::setDown(House *houseP) 
{
	down = houseP;
}

void House::setRight(House *houseP) 
{
	right = houseP;
}

void House::setLeft(House *houseP) 
{
	left = houseP;
}

House *House::getUp() const 
{
	if (up != NULL)
		return up;
	else 
	{
		std::cout << "NULL cannot be returned" << std::endl;
		exit(1);
	}
}

House *House::getDown() const 
{
	if (down != NULL)
		return down;
	else 
	{
		std::cout << "NULL cannot be returned" << std::endl;
		exit(1);
	}
}

House *House::getRight() const 
{
	if (right != NULL)
		return right;
	else 
	{
		std::cout << "NULL cannot be returned" << std::endl;
		exit(1);
	}
}

House *House::getLeft() const 
{
	if (left != NULL)
		return left;
	else 
	{
		std::cout << "NULL cannot be returned" << std::endl;
		exit(1);
	}
}

bool House::isComplete() 
{
	return actionComplete;
}
