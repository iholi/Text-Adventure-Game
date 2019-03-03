#ifndef ENGINE_H
#define ENGINE_H
#include "world.h"
#include "location.h"
#include "player.h"
#include "list.h"

void engine();
Player createPlayer();
void createSpaceship(House *&roomKey, House *&roomLiving2, House *&roomLiving, House *&roomMonster,                                  House *&roomEntrance, House *&room1, House *&room2, House *&room3,                                      	     House *&roomKitchen, House *&roomLight);
void setSpace(House *&setSpace, House *up, House *down, House *right, House *left);

void introMessage(std::string);
void loseTime(int &timeIn, int &stageIn);
void getGoal(int);
int menuInputValidation();
void displayLivingMenu();
void logicLivingR(House *&locationIn, int &timeIn, int &stageIn, List &pack);
void displayRoom1Menu();
void logicRoom1R(House *&locationIn, int &timeIn, int &stageIn, List &pack);
void displayRoom2Menu();
void logicRoom2R(House *&locationIn, int &timeIn, int &stageIn, List &pack);
void displayRoom3Menu();
void logicRoom3R(House *&locationIn, int &timeIn, int &stageIn, List &pack);
void displayKitchenMenu();
void logicKitchen(House *&locationIn, int &timeIn, int &stageIn, List &pack);
void displayLightMenu();
void logicLight(House *&locationIn, int &timeIn, int &stageIn, List &pack);
void displayMonsterMenu();
void logicMonsterR(House *&locationIn, int &timeIn, int &stageIn, List &pack);
void displayEntranceMenu();
void logicEntranceR(House *&locationIn, int &timeIn, int &stageIn, List &pack);
void displayLivingR2Menu();
void logicLivingR2(House *&locationIn, int &timeIn, int &stageIn, List &pack);
void displayKeyMenu();
void logicKeyR(House *&locationIn, int &timeIn, int &stageIn, List &pack);

#endif
