#ifndef LOCATION_H
#define LOCATION_H
#include "world.h"
#include <string>

// Living Room
class LivingR: public House 
{
private:
	void introMessage(std::string);

public:
	virtual void specialAction();
};

// Key Room
class KeyR : public House 
{
public:
	virtual void specialAction();
};

// Entrance Room
class EntranceR : public House 
{
public:
	virtual void specialAction();
};

// Monster Room
class MonsterR : public House 
{
public:
	virtual void specialAction();
};

// Room 1
class Room1 : public House 
{
public:
        virtual void specialAction();
};

// Room 2
class Room2 : public House 
{
public:
        virtual void specialAction();
};

// Room 3
class Room3 : public House
{
public:
        virtual void specialAction();
};

// Kitchen
class Kitchen : public House
{
public:
        virtual void specialAction();
};

// Light
class Light : public House
{
public:
        virtual void specialAction();
};

#endif

// Living Room2
class LivingR2 : public House 
{
public:
	virtual void specialAction();
};
