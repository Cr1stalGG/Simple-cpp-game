#include <iostream>
class Enemy
{
private:
	int HEALTH = 75;
	int DAMAGE = 10;
	int xPos = 5;
	int yPos = 5;
	int bonus;

	//getters & setters
public:
	Enemy(int bonus) {
		this->bonus = bonus;
	}
	int getHEALTH() {
		return HEALTH;
	}
	int getDAMAGE() {
		return DAMAGE;
	}
	int getXPos() {
		return xPos;
	}
	int getYPos() {
		return yPos;
	}
	void setHEALTH(int newHEALTH) {
		HEALTH = newHEALTH;
	}
	void setDAMAGE(int damageBoost) {
		DAMAGE += damageBoost;
	}
public:

	//logic functions
	void resetPosition(int HEIGHT, int WIDTH) {
		xPos = std::rand() % (WIDTH - 2) + 1;
		yPos = std::rand() % (HEIGHT - 2) + 1;
	}

};


