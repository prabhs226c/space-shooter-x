#pragma once
#include "Ship.h"
class Enemy :
	public Ship
{
public:
	static int enemyCount;
	void destroy();
	int type;
	Enemy(int _type, int _health, int _xPos, int _yPos);

};

