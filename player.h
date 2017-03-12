//
//  player.h
//  C++ Playground
//
//  Created by Joseph Wicker on 1/4/17.
//  Copyright © 2017 Cavalier Productions. All rights reserved.
//

#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "inventory.h"
#include "item.h"

using namespace std;

class Player {
private:
	string name;
	int age;

	int health;
	int maxHealth;

	int attack;
	int strength;
	int defense;

	int experience;
	int level;
	int nextLevel;

	Inventory inv;

public:
	// Constructor
	Player(string name, int age);

	void setName(string name);
	string getName() {return name;}

	void setAge(int age);
	int getAge() {return age;}

	void addExp(int exp);
	void levelUp();

	int getLevel() {return level;}

	int dealDamage();
	void takeDamage(int damageDelt);

	bool isAlive() {return health > 0;}
	void heal();
	string vitals();

	void addToInventory(Item item);

	void showInventory();

	void useItem(int slot);
};

#endif