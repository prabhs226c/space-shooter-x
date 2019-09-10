#include "Enemy.h"


void Enemy::destroy()
{
	health = 0;
}

Enemy::Enemy(int _type,int _health,int _xPos,int _yPos):Ship(_health,0,(_type==1?"e":"P"),_xPos,_yPos)
{
	type = _type;
}
