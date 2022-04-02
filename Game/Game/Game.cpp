#include <iostream>
#include <conio.h>
#include "Person.h"
#include "Enemy.h"
#include "Heal.h"

using namespace std;

//map settings
#define HEIGHT 20
#define WIDTH 50

//enemy settings
Enemy enemy = Enemy(rand() % 5 + 1);

//heal settings
Heal heal;
bool isHealTaken = true;

//persons settings
int x = 10;
int y = 10;
Person person;

//game settings
bool isGameOver = false;

//-------functions-------

bool fight() {
	if (person.getXPos() == enemy.getXPos() && person.getYPos() == enemy.getYPos()) {
		enemy.setHEALTH(enemy.getHEALTH() - person.getDAMAGE());
		person.setHEALTH(enemy.getDAMAGE());
		return true;
	}
	else {
		return false;
	}
}

//drawing map function
void graphic()
{
	for (int i = 0; i < HEIGHT; i++) {
		for (int ii = 0; ii < WIDTH; ii++) {
			if (i == 0 || i == HEIGHT - 1 || ii == 0 || ii == WIDTH - 1) {
				cout << "#";
			}
			//drawing person
			else if (i == person.getYPos() && ii == person.getXPos()) {
				cout << "P";
			}
			//drawing enemy
			else if (i == enemy.getYPos() && ii == enemy.getXPos()) {
				cout << "E";
			}
			//drawing heal point
			else if (!isHealTaken) {
				if (i == heal.getYPos() && ii == heal.getXPos()) {
					cout << "+";
				}
				else {
					cout << " ";
				}
			}
			else {
				cout << " ";
			}
		}
		cout << endl;
	}
	person.stats();
}

int gameOver() {
	system("cls");
	printf("Game Over...");
	return 0;
}

void logic()
{
	//game process logic
	while (!isGameOver) {
		//enemy dying logic
		if (enemy.getHEALTH() <= 0) {
			person.setScore(1);
			enemy.setHEALTH(100);
			enemy.resetPosition(HEIGHT, WIDTH);
			heal.setHealPower(30, 100);
			heal.setPosition(HEIGHT, WIDTH);
			isHealTaken = false;
		}
		//taking heal logic
		if (person.getXPos() == heal.getXPos() && person.getYPos() == heal.getYPos()) {
			isHealTaken = true;
			person.setHeal(heal.getHeal());
		}
		//person dying logic
		if (person.getHEALTH() <= 0) {
			isGameOver = true;
			gameOver();
		}
		//movement logic
		switch (_getch()) {
		case 'w':
			if (fight()) {
				system("cls");
				graphic();
			}
			else if (person.getYPos() == 1) {
				continue;
			}
			else {
				person.setYPos(person.getYPos() - 1);
				system("cls");
				graphic();
			}
			break;
		case 's':
			if (fight()) {
				system("cls");
				graphic();
			}
			else if (person.getYPos() == HEIGHT - 2) {
				continue;
			}
			else {
				person.setYPos(person.getYPos() + 1);
				system("cls");
				graphic();
			}
			break;
		case 'd':
			if (fight()) {
				system("cls");
				graphic();
			}
			else if (person.getXPos() == WIDTH - 2) {
				continue;
			}
			else {
				person.setXPos(person.getXPos() + 1);
				system("cls");
				graphic();
			}
			break;
		case 'a':
			if (fight()) {
				system("cls");
				graphic();
			}
			else if (person.getXPos() == 1) {
				continue;
			}
			else {
				person.setXPos(person.getXPos() - 1);
				system("cls");
				graphic();
			}
			break;
		}

	}

}

int main()
{
	graphic();
	logic();

	return 0;
}
