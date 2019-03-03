#ifndef WORLD_H
#define WORLD_H
#include <iostream>

class House 
{

protected:
	House *up;
	House *down;
	House *right;
	House *left;
	bool actionComplete;

public:
	House();

	virtual ~House();

	void setUp(House *);
	void setDown(House *);
	void setRight(House *);
	void setLeft(House *);
	House *getUp() const;
	House *getDown() const;
	House *getRight() const;
	House *getLeft() const;
	bool isComplete();

	virtual void specialAction() = 0;

};
#endif
