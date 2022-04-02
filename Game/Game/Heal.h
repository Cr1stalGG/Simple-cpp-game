#include <iostream>
class Heal
{
private:
	int HEAL;
	int xPos = 9999;
	int yPos = 9999;

	//getters & setters
public:
	int getXPos() {
		return xPos;
	}
	int getYPos() {
		return yPos;
	}
	int getHeal() {
		return HEAL;
	}
	void setPosition(int HEIGHT, int WIDTH) {
		xPos = rand() % (WIDTH - 2) + 1;
		yPos = rand() % (HEIGHT - 2) + 1;
	}
	void setHealPower(int min, int max) {
		HEAL = rand() % max + min;
	}

	//logic functions
//public:

};


