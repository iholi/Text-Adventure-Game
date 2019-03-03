#include "location.h"

void KeyR::specialAction() 
{
        std::cout << "\n**You found the key. Now you can open the door of the Room 1, but"
		  << "you need there is a monster in the Monster room, so you need to find"
		  << "find something to kill the monster"<< std::endl;	
}

void LivingR::specialAction() 
{
	actionComplete = true;
}

void EntranceR::specialAction() 
{	
	std::cout << "\n**Congratulation! You and your family were able to escape. You saved your family," 
		  << "you are a HERO!!!"<< std::endl;
}

void MonsterR::specialAction() 
{	
	std::cout << "\n**You killed the monster. Now you are able to open the door with the key\n" << std::endl;
	actionComplete = true;
}

void LivingR2::specialAction() 
{	
}

void Room1::specialAction() 
{        
        std::cout << "\n**You saved your family. Now go and find a way to leave the house" << std::endl;
}

void Room2::specialAction() 
{
        std::cout << "\n**Now that you have a gun, you are able to enter Monster Room and kill the monster."			  << std::endl;
}

void Room3::specialAction() 
{
}

void Kitchen::specialAction()
{
}

void Light::specialAction() 
{      
        std::cout << "\n**Now that you have a candle, you are able to enter the room3." << std::endl;
}
