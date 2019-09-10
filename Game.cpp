#include "Game.h"

void Game::move(int _x, int _y)
{
	erase();
	xPos += _x;
	yPos += _y;
	draw();
}

Game::Game(string _graphic, int _xpos, int _ypos)
{
	graphic = _graphic;
	xPos = _xpos;
	yPos = _ypos;
}


void Game::draw()
{
	UIKit::gotoXY(xPos, yPos);
	cout << graphic;
}

void Game::erase()
{
	
	UIKit::gotoXY(xPos, yPos);
	cout << " ";
}

