#pragma once
#include "Game.h"
class Ship :
	public Game
{
public:
	int health;
	int livesRemaining;
	Ship(int _health,int _lives,string _graphic,int _xpos,int _ypos);
};

