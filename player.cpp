#include "player.h"

Player::Player(std::string nameIn) 
{
	name = nameIn;
}

std::string Player::getName() const 
{
	return name;
}
