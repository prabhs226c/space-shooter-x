#include "Ship.h"

Ship::Ship(int _health, int _lives,string _graphic, int _xpos,int _ypos):Game(_graphic,_xpos,_ypos)
{
	health = _health;
	livesRemaining = _lives;
}
