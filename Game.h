#pragma once

#include<iostream>
#include<string>
#include <conio.h>
#include "UIKit.h"

using namespace std;
class Game
{
public:
	string graphic; //for graphical representation of an entity
	static int difficulty;
	int xPos;
	int yPos;
	void draw();
	void erase();
	void move(int _x, int _y);
	Game(string _graphic,int _xpos,int _ypos);

};

