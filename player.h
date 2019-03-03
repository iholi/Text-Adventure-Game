#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <iostream>
#include "world.h"

class Player 
{

private:
	std::string name;

public:
	Player(std::string);
	std::string getName() const;

};

#endif
