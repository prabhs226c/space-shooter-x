// space Shooter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Game.h"
#include "Ship.h"
#include "Player.h"
#include "Enemy.h"
#include "UIKit.h"
#include <conio.h>
#include <time.h>  

int Game::difficulty = 1;
int Enemy::enemyCount = 0;

int getInt(int _mx,int _mn);
void fullscreen();
void initializeGame();
int main()
{
	long timer = time(NULL);
	srand(time(NULL));
	initializeGame(); // set game difficulty and enter full screen mode
	Player* hero = new Player(0);
	UIKit::gotoXY(100, 100);
	hero->yPos = 50;
	hero->xPos = 100;
	cout << hero->graphic;
	
	// spawning 5 random enemies to get the game running
	Enemy** vilian = new Enemy*[50];
	for (int i = 0; i < 50; i++) {

		vilian[i] = nullptr;
	}

	for (int i = 0; i < 5; i++) {
		int enemy_type = (rand() % 2 + 1);
		int _health;
		if (enemy_type == 1) {
			switch (Game::difficulty) {
			case 1:
				_health = 1;
				break;
			case 2:
				_health = 2;
				break;
			case 3:
				_health = 3;
				break;
			};
		}
		else {
			switch (Game::difficulty) {
			case 1:
				_health = 2;
				break;
			case 2:
				_health = 4;
				break;
			case 3:
				_health = 6;
				break;
			};
		}
		vilian[i] = new Enemy(enemy_type,_health,(rand()%200+2), (rand() % 30 + 2));
		UIKit::gotoXY(vilian[i]->xPos, vilian[i]->yPos);

		cout << vilian[i]->graphic;
		Enemy::enemyCount = i;
	}

	while (true){

		hero->detectInput();
		if (time(NULL) - timer == 1) {
			for (int i = 0; i < 50; i++) {
				if (vilian[i] != nullptr && vilian[i]->health != 0) {
					if (vilian[i]->yPos < 50) {
						vilian[i]->move(0, 1);
					}
					else {
						vilian[i]->health = 0;
						UIKit::gotoXY(vilian[i]->xPos, vilian[i]->yPos);
						cout << " ";
					}
				}
			}
			timer = time(NULL);
		}
	}
	/*	while ((time(NULL) - timer) != 5) { cout << "hsd" << endl; }
		if ((time(NULL) - timer) == 5) {
			cout << "5 passed";
		}*/
		

	
	for (int i = 0; i < 50; i++) {
		delete vilian[i];
		vilian[i] = nullptr;
	}
}

void initializeGame(){
	cout << "Please Select Difficulty\n 1: Easy \n 2: Medium\n 3: Hard\n";
	Game::difficulty = getInt(3, 1);
	system("CLS");
	fullscreen();
}
int getInt(int _mx, int _mn)
{
	int val;
	cin >> val;
	while (cin.fail() || cin.peek() != '\n' || (val < _mn || val > _mx)) {
		cin.clear();
		cin.ignore(512, '\n');
		cout << "Please enter correct value \n";
		cin >> val;
		return val;
	}
}

void fullscreen()          //another cool trick that I use to make it full screen or back to normal size
{
	keybd_event(VK_MENU, 0x38, 0, 0);
	keybd_event(VK_RETURN, 0x1c, 0, 0);
	keybd_event(VK_RETURN, 0x1c, KEYEVENTF_KEYUP, 0);
	keybd_event(VK_MENU, 0x38, KEYEVENTF_KEYUP, 0);
}