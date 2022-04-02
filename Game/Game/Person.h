#include <iostream>
class Person
{
private:
	int HEALTH = 100;
	int DAMAGE = 15;
	int SCORE = 0;
	int xPos = 10;
	int yPos = 10;

	//getters & setters
public:
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
	void setHEALTH(int takenDamage) {
		HEALTH -= takenDamage;
	}
	void setHeal(int healPower) {
		HEALTH += healPower;
	}
	void setDAMAGE(int damageBoost) {
		DAMAGE += damageBoost;
	}
	void setXPos(int xpos) {
		xPos = xpos;
	}
	void setYPos(int ypos) {
		yPos = ypos;
	}
	void setScore(int bonus) {
		SCORE += bonus;
	}

	//logic functions
public:
	void stats() {
		printf("Stats\n");
		printf("Health: %d\n", HEALTH);
		printf("Damage: %d\n", DAMAGE);
		printf("Score: %d\n", SCORE);
	}

};


