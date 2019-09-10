#include "Player.h"
Player::Player(int _score) :Ship(10, 3, "A",100, 100) {
	int score = _score;
}

void Player::detectInput() {

	int step = 1;
	char key = ' ';
	
			getInput(&key);

			//x = UIKit::whereX();
			//y = UIKit::whereY();
			if (key == 'D' || key == 'd') {  // move right
				if (xPos < 210) {
					move(1, 0);
				}
				
			}
			if (key == 'A' || key == 'a') { // move left
				if (xPos > 1) {
				move(-1, 0);
				}
			}
			/* else if (key == ' ') { // shoot
				//new Bullet();
				UIKit::gotoXY(x, ++y);
				cout << "*";
			}*/
		
	
}

bool Player::getInput(char* c)
{
	if (_kbhit())
	{
		*c = _getch();
		return true; // Key Was Hit
	}
	return false; // No keys were pressed
}