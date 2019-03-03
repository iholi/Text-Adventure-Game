#include "engine.h"

void engine() 
{
	House *roomKey = new KeyR;
	House *roomLiving2 = new LivingR2;
	House *roomLiving = new LivingR;
	House *roomMonster = new MonsterR;
	House *roomEntrance = new EntranceR;
	House *room1 = new Room1;
	House *room2 = new Room2;
	House *room3 = new Room3;
	House *roomKitchen = new Kitchen;
	House *roomLight = new Light;
	Player player = createPlayer();
	House *playerLocation = roomLiving;
	int stage = 0;
	List backpack;
	int time = 500;
	createSpaceship(roomKey, roomLiving2, roomLiving, roomMonster, roomEntrance, 
	room1, room2, room3, roomKitchen, roomLight);
	introMessage(player.getName());
	logicLivingR(playerLocation, time, stage, backpack);
}

Player createPlayer() 
{
	std::cout << "\nTo start the game, enter a name for the player.\n: ";
	std::string name;
	std::getline(std::cin, name);
	Player tempPlayer(name);
	return tempPlayer; 
}

void createSpaceship(House *&Key, House *&Liv2, House *&Liv, House *&MONS, House *&ENTRA, 
		House *&ROM1, House *&ROM2, House *&ROM3, House *&Kit, House *&Light) 
{
	//Room position ( Room, UP, DOWN, RIGHT, LEFT)
	setSpace(Key, ROM3, ROM2, Liv2, NULL);
	setSpace(Liv2, NULL, NULL, Liv, Key);
	setSpace(Liv, MONS, Kit, ENTRA, Liv2);
	setSpace(MONS, NULL, Liv, NULL, ROM1);
	setSpace(ENTRA, NULL, NULL, NULL, Liv);
	setSpace(ROM1, NULL, NULL, MONS, NULL);
        setSpace(ROM2, Key, NULL, NULL, NULL);
	setSpace(ROM3, NULL, Key, NULL, NULL);
	setSpace(Kit, Liv, NULL, NULL, Light);
	setSpace(Light, NULL, NULL, Kit, NULL);	
}

void setSpace(House *&setSpace, House *up, House *down, House *right, House *left) 
{
	setSpace->setUp(up);
	setSpace->setDown(down);
	setSpace->setRight(right);
	setSpace->setLeft(left);
}

void introMessage(std::string nameIn) 
{
	std::cout << "\n(The sound of the TV wakes you up)\n"
		  << "(You rub your eyes)\n"
		  << "(Someone start speaking to you)\n"
		  << "Hi " << nameIn <<  " I want to play a game with you!"
		  << " I've kidnapped your family and is being held prisoner"
		  << " somewhere the house, your mission is to find and rescue"
		  << " them. My advice to you is to hurry... if you want your"
		  << " family safe of course. LET THE GAME BEGIN!"<< std::endl;
}

void loseTime(int &timeIn, int &stageIn) 
{
	timeIn -= 6;
}

void getGoal(int stageIn) 
{
	std::cout << "\nOverview:\nYour family and you got kidnaped by a guy. Your goal is to save "
		  << "them and escape with them " << std::endl;
}

int menuInputValidation() 
{
	int input;
	std::cin >> input;
	while(std::cin.fail()) 
	{
        std::cout << "Error, try to enter the numbers given." << std::endl;
        std::cin.clear();
        std::cin.ignore(256,'\n');
        std::cout << "Try again: " << std::endl;
        std::cin >> input;
	}
    	return input;
}

void displayLightMenu()
{
        std::cout << "\nPlayer Location: Kitchen\n"
                        << "Menu:\n"
                        << "0 = See mission.\n"
                        << "1 = Take candle.\n"
                        << "2 = Go east\n"
                        << "3 = See what is in your pocket.\n"
                        << "Type in the number for the action to take: ";
}

void logicLight(House *&locationIn, int &timeIn, int &stageIn, List &pack)
{
        int input;
        loseTime(timeIn, stageIn);
        do 
	{
		displayLightMenu();
		input = menuInputValidation();
		if (input == 0) 
		{	
        		getGoal(stageIn);
        		logicLight(locationIn, timeIn, stageIn, pack);
        	}
		else if (input == 1 && !pack.inPocket("Candle")) 
		{         
			locationIn->specialAction();
        		std::string tool = "Candle";
        		pack.addItem(tool);
        		pack.display();
        		logicLight(locationIn, timeIn, stageIn, pack);
		}
		else if (input == 1 && pack.inPocket("Candle")) 
		{
       			std::cout << "\nYou already took the candle." << std::endl;
        		logicLight(locationIn, timeIn, stageIn, pack);
        	}
 	        else if (input == 2) {
        		std::cout << "\nYou moved to east." << std::endl;
        		locationIn = locationIn->getRight();
        		logicKitchen(locationIn, timeIn, stageIn, pack);
        	}
        	else if (input == 3) {
      			pack.display();
        		logicLight(locationIn, timeIn, stageIn, pack);
        	}
        	} while (input < 0 || input > 3);
}

void displayKitchenMenu() 
{
    	      std::cout << "\nPlayer Location: Kitchen\n"
                        << "Menu:\n"
                        << "0 = See mission.\n"
                        << "1 = Look around.\n"
                        << "2 = Go north.\n"
			<< "3 = Go west.\n"
                        << "4 = See what is in your pocket.\n"
                        << "Type in the number for the action to take: ";
}

void logicKitchen(House *&locationIn, int &timeIn, int &stageIn, List &pack) 
{
        int input;
        loseTime(timeIn, stageIn);
        do {
                displayKitchenMenu();
                input = menuInputValidation();
                if (input == 0) 
		{
                        getGoal(stageIn);
                        logicKitchen(locationIn, timeIn, stageIn, pack);
                }
                 else if (input == 1) 
		{
                        std::cout << "\nThere is nothing in this room, only spoiled food (ugh)." << std::endl;
                        logicKitchen(locationIn, timeIn, stageIn, pack);
                }
                else if (input == 2) 
		{
        	        std::cout << "\nYou moved to north." << std::endl;
 	                locationIn = locationIn->getUp();
                	logicLivingR(locationIn, timeIn, stageIn, pack);
                }
                else if (input == 3) 
		{
 	                std::cout << "\nYou moved to west." << std::endl;
                	locationIn = locationIn->getLeft();
                	logicLight(locationIn, timeIn, stageIn, pack);
                }
                else if (input == 4) 
		{
                        pack.display();
                        logicKitchen(locationIn, timeIn, stageIn, pack);
                }
                } while (input < 0 || input > 4);
}

void displayRoom3Menu() 
{
              std::cout << "\nPlayer Location: Room3\n"
                        << "Menu:\n"
                        << "0 = See mission.\n"
                        << "1 = Look around.\n"
			<< "2 = Go south.\n"
                        << "3 = See what is in your pocket.\n"
                        << "Type in the number for the action to take: ";
}

void logicRoom3(House *&locationIn, int &timeIn, int &stageIn, List &pack) 
{
        int input;
        loseTime(timeIn, stageIn);
        do {
                displayRoom3Menu();
                input = menuInputValidation();
                if (input == 0) 
		{
                        getGoal(stageIn);
                        logicRoom3(locationIn, timeIn, stageIn, pack);
                }
                 else if (input == 1) 
		{
                        std::cout << "\nThere is nothing in this room." << std::endl;
                        logicRoom3(locationIn, timeIn, stageIn, pack);
                }
                else if (input == 2) 
		{
        	        std::cout << "\nYou moved to south." << std::endl;
 	                locationIn = locationIn->getDown();
                	logicKeyR(locationIn, timeIn, stageIn, pack);
                }
                else if (input == 3) 
		{
                        pack.display();
                        logicRoom3(locationIn, timeIn, stageIn, pack);
                }
 		} while (input < 0 || input > 3);
}

void displayRoom2Menu() 
{
        std::cout << "\nPlayer Location: Room2\n"
                        << "Menu:\n"
                        << "0 = See mission.\n"
                        << "1 = Open bag.\n"
                        << "2 = Go north.\n"
                        << "3 = See what is in your pocket.\n"
                        << "Type in the number for the action to take: ";
}	

void logicRoom2(House *&locationIn, int &timeIn, int &stageIn, List &pack) 
{
        int input;
        loseTime(timeIn, stageIn);
        do {
                displayRoom2Menu();
                input = menuInputValidation();
                if (input == 0)
		{
			getGoal(stageIn);
        	        logicRoom2(locationIn, timeIn, stageIn, pack);
		}
		else if (input == 1 && !pack.inPocket("Gun")) 
		{    
                	locationIn->specialAction();
                	std::string tool = "Gun";
                	pack.addItem(tool);
               		pack.display();
                	logicRoom2(locationIn, timeIn, stageIn, pack);
                }
                else if (input == 1 && pack.inPocket("Gun")) 
		{
                	std::cout << "\nThe bag is empty." << std::endl;
                	logicRoom2(locationIn, timeIn, stageIn, pack);
                }
                else if (input == 2) 
		{
                	std::cout << "\nYou moved to north." << std::endl;
                	locationIn = locationIn->getUp();
                	logicKeyR(locationIn, timeIn, stageIn, pack);
                }
                else if (input == 3) 
		{
                	pack.display();
                	logicRoom2(locationIn, timeIn, stageIn, pack);
                }		
	        } while (input < 0 || input > 3);
}

void displayRoom1Menu() 
{
        std::cout << "\nPlayer Location: Room1\n"
                        << "Menu:\n"
                        << "0 = See mission.\n"
                        << "1 = Save family.\n"
                        << "2 = Go east.\n"
                        << "3 = See what is in your pocket.\n"
                        << "Type in the number for the action to take: ";
}

void logicRoom1(House *&locationIn, int &timeIn, int &stageIn, List &pack) 
{
        int input;
        loseTime(timeIn, stageIn);
        do {
                displayRoom1Menu();
                input = menuInputValidation();
                if (input == 0) 
		{
                        getGoal(stageIn);
                        logicRoom1(locationIn, timeIn, stageIn, pack);
                }
                else if (input == 1 && !pack.inPocket("family")) 
		{
			std::cout << "\nYou saved your family" << std::endl;
                        std::string tool = "family";
			locationIn->specialAction();
                        pack.addItem(tool);
                        pack.display();
                        logicRoom1(locationIn, timeIn, stageIn, pack);
                }
                else if (input == 1 && pack.inPocket("family")) 
		{
                        std::cout << "\nYou already saved your family, now you need to escape with them" << std::endl;
                        logicRoom1(locationIn, timeIn, stageIn, pack);
                }
		else if (input == 2) 
		{
                        std::cout << "\nYou moved to east ." << std::endl;
                        locationIn = locationIn->getRight();
			logicMonsterR(locationIn, timeIn, stageIn, pack);
		}
		else if (input == 3) 
		{
			pack.display();
			logicRoom1(locationIn, timeIn, stageIn, pack);
		}
		} while (input < 0 || input > 3);
}


void displayLivingMenu() 
{
	      std::cout << "\nPlayer Location: living Room\n"
			<< "Menu:\n"
			<< "0 = See mission.\n"
			<< "1 = Go south.\n"
			<< "2 = Go north.\n"
			<< "3 = Go east.\n"
			<< "4 = Go west.\n"
			<< "5 = See what is in your pocket\n"
			<< "Type in the number for the action to take: ";
}

void logicLivingR(House *&locationIn, int &timeIn, int &stageIn, List &pack) 
{
	int input;
	loseTime(timeIn, stageIn);
	do {
		displayLivingMenu();
		input = menuInputValidation();
		if (input == 0) 
		{
			getGoal(stageIn);
			logicLivingR(locationIn, timeIn, stageIn, pack);
		}
		else if (input == 1) 
		{
			std::cout << "\nYou moved to south ." << std::endl;
			locationIn = locationIn->getDown();
			logicKitchen(locationIn, timeIn, stageIn, pack);
		}
		else if (input == 2 && pack.inPocket("Gun")) 
		{
			locationIn->specialAction();
			locationIn = locationIn->getUp();
			logicMonsterR(locationIn, timeIn, stageIn, pack);
		}
		else if (input == 2 && !pack.inPocket("Gun")) 
		{
			std::cout << "\nYou cannot go inside. There is a monster and "
			<< "you need to find a object to kill it" << std::endl;
			logicLivingR(locationIn, timeIn, stageIn, pack);
		}
		else if (input == 3) 
		{
			std::cout << "\nYou move to east"<< std::endl;
			locationIn = locationIn->getRight();
			logicEntranceR(locationIn, timeIn, stageIn, pack);
		}
		else if (input == 4) 
		{
			std::cout << "\nYou moved to west" << std::endl;
			locationIn = locationIn->getLeft();
			logicLivingR2(locationIn, timeIn, stageIn, pack);
		}
		else if (input == 5) 
		{
			pack.display();
			logicLivingR(locationIn, timeIn, stageIn, pack);
		}
		} while (input < 0 || input > 5);
}

void displayMonsterMenu() 
{
	      std::cout << "\nPlayer Location: Monster Room\n"
			<< "Menu:\n"
                        << "0 = See mission.\n"
                        << "1 = Kill monster.\n"
                        << "2 = Go south.\n"
                        << "3 = Open door and enter.\n"
			<< "4 = See what is in your pocket.\n"
			<< "Type in the number for the action to take: ";
}

void logicMonsterR(House *&locationIn, int &timeIn, int &stageIn, List &pack) 
{
	int input;
	loseTime(timeIn, stageIn);
	do {
		displayMonsterMenu();
		input = menuInputValidation();
		if (input == 0) 
		{
			getGoal(stageIn);
			logicMonsterR(locationIn, timeIn, stageIn, pack);
		}
		else if (input == 1 && !pack.inPocket("monster")) 
		{
			std::cout << "\nYou killed the monster" << std::endl;
			locationIn->specialAction();
			std::string tool = "monster";
			pack.addItem(tool);
			pack.display();
			logicMonsterR(locationIn, timeIn, stageIn, pack);
		}
		else if (input == 1 && pack.inPocket("monster")) 
		{
			std::cout << "\nYou already killed the monster"<< std::endl;
			logicMonsterR(locationIn, timeIn, stageIn, pack);
		}
		else if (input == 2) 
		{
			std::cout << "\nYou moved to south" << std::endl;
			locationIn = locationIn->getDown();
			logicLivingR(locationIn, timeIn, stageIn, pack);
		}
                else if (input == 3 && pack.inPocket("Key") && pack.inPocket("monster")) 
		{
                        locationIn = locationIn->getLeft();
                        logicRoom1(locationIn, timeIn, stageIn, pack);
                }
                else if (input == 3 && !pack.inPocket("monster") && !pack.inPocket("key")) 
		{
                        std::cout << "\nYou need to find the key and kill the monster"
                                        << std::endl;
                        logicMonsterR(locationIn, timeIn, stageIn, pack);
                }
		else if (input == 4) 
		{
			pack.display();
			logicMonsterR(locationIn, timeIn, stageIn, pack);
		}
		} while (input < 0 || input > 4);
}

void displayEntranceMenu() 
{
	      std::cout << "\nPlayer Location: Entrance Room\n"
			<< "Menu:\n"
			<< "0 = See mission.\n"
			<< "1 = Open door.\n"
			<< "2 = Move west\n"
			<< "3 = See what is in your Pocket.\n"
			<< "Type in the number for the action to take: ";
}

void logicEntranceR(House *&locationIn, int &timeIn, int &stageIn, List &pack) 
{
	int input;
	loseTime(timeIn, stageIn);
	do {
		displayEntranceMenu();
		input = menuInputValidation();
		if (input == 0) 
		{
			getGoal(stageIn);
			logicEntranceR(locationIn, timeIn, stageIn, pack);
		}
		else if (input == 1 && pack.inPocket("family")) 
		{
			locationIn->specialAction();
			exit(1);
			//locationIn = locationIn->getDown();
			logicEntranceR(locationIn, timeIn, stageIn, pack);
		}
		else if (input == 1 && !pack.inPocket("family")) 
		{
			std::cout << "\nYou need to rescue your family first."
					<< std::endl;
			logicEntranceR(locationIn, timeIn, stageIn, pack);
		}
		else if (input == 2) 
		{
			std::cout << "\nYou moved to west" << std::endl;
			locationIn = locationIn->getLeft();
			logicLivingR(locationIn, timeIn, stageIn, pack);
		}
		else if (input == 3) 
		{
			pack.display();
			logicEntranceR(locationIn, timeIn, stageIn, pack);
		}
		} while (input < 0 || input > 3);
}

void displayLivingR2Menu() 
{
	      std::cout << "\nPlayer Location: Living Room 2\n"
			<< "Menu:\n"
			<< "0 = See mission.\n"
			<< "1 = Go west.\n"
			<< "2 = Go east.\n"
			<< "3 = See what is in your Pocket.\n"
			<< "Type in the number for the action to take: ";
}

void logicLivingR2(House *&locationIn, int &timeIn, int &stageIn, List &pack) 
{
	int input;
	loseTime(timeIn, stageIn);
	do {
		displayLivingR2Menu();
		input = menuInputValidation();
		if (input == 0) 
		{
			getGoal(stageIn);
			logicLivingR2(locationIn, timeIn, stageIn, pack);
		}
		else if (input == 1) 
		{
			std::cout << "\nYou moved to west"<< std::endl;
                        locationIn = locationIn->getLeft();
			logicKeyR(locationIn, timeIn, stageIn, pack);
		}
		else if (input == 2) 
		{
			std::cout << "\nYou moved to east" << std::endl;
			locationIn = locationIn->getRight();
			logicLivingR(locationIn, timeIn, stageIn, pack);
		}
		else if (input == 3) 
		{
			pack.display();
			logicLivingR2(locationIn, timeIn, stageIn, pack);
		}
		} while (input < 0 || input > 3);
}

void displayKeyMenu() 
{
	      std::cout << "\nPlayer location: Key Room\n"
			<< "Menu:\n"
			<< "0 = See current goal.\n"
			<< "1 = Go north\n"
			<< "2 = Open box.\n"
			<< "3 = Go east.\n"
			<< "4 = Go south.\n"
			<< "5 = See what is in your Pocket.\n"
			<< "Type in the number for the action to take: ";
}

void logicKeyR(House *&locationIn, int &timeIn, int &stageIn, List &pack) 
{
	int input;
	loseTime(timeIn, stageIn);
	do {
		displayKeyMenu();
		input = menuInputValidation();
		if (input == 0) 
		{
			getGoal(stageIn);
			logicKeyR(locationIn, timeIn, stageIn, pack);
		}
                else if (input == 1 && !pack.inPocket("Candle")) 
		{
                        std::cout << "\nThe room is too dark, you need a candle to be able to enter and see"<< std::endl;
                        logicKeyR(locationIn, timeIn, stageIn, pack);
                }
                else if (input == 1 && pack.inPocket("Candle")) 
		{
                        locationIn = locationIn->getUp();
                        logicRoom3(locationIn, timeIn, stageIn, pack);
                }
		else if (input == 2 && !pack.inPocket("Key")) 
		{
			std::cout << "\nAfter opening the box, you put the key in your pocket " << std::endl;
			std::string tool = "Key";
			locationIn->specialAction();
			pack.addItem(tool);
			pack.display();
			logicKeyR(locationIn, timeIn, stageIn, pack);
		}
		else if (input == 2 && pack.inPocket("Key")) 
		{
			std::cout << "\nThere is in nothing else in the box " << std::endl;
			logicKeyR(locationIn, timeIn, stageIn, pack);
		}
		else if (input == 3) 
		{
			std::cout << "\nYou moved to east"<< std::endl;
			locationIn = locationIn->getRight();
			logicLivingR2(locationIn, timeIn, stageIn, pack);
		}
		else if (input == 4) 
		{
			std::cout << "\nYou moved to south." << std::endl;
			locationIn = locationIn->getDown();
			logicRoom2(locationIn, timeIn, stageIn, pack);
		}
		else if (input == 5) 
		{
			pack.display();
			logicKeyR(locationIn, timeIn, stageIn, pack);
		}
		} while (input < 0 || input > 5);
}

