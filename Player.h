#pragma once
#include "Ship.h"


class Player :
	public Ship
{
public:
	int score;
	Player(int _score);
	void detectInput();
	bool getInput(char* c);
};

