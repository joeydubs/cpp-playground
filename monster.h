//
//  monster.h
//  C++ Playground
//
//  Created by Joseph Wicker on 1/4/17.
//  Copyright © 2017 Cavalier Productions. All rights reserved.
//

#ifndef MONSTER_H
#define MONSTER_H

#include <string>
#include <array>
#include "item.h"

using namespace std;

class Monster {
private:
	string name;

	int health;
	int maxHealth;

	int attack;
	int strength;
	int defense;

	array <Item, 6> dropTable {
		Item("Some Sword", 1, 1),
		Item("Some Shield", 1, 1),
		Item("Some Helmet", 1, 1),
		Item("Some Chestplate", 1, 1),
		Item("Some Platelegs", 1, 1),
		Item("Some Off-Hand Weapon", 1, 1)
	};


public:
	// Constructor
	Monster(string name, int maxHealth);

	int expDrop;

	string getName() {return name;}

	int dealDamage();
	void takeDamage(int damageDelt);

	bool isAlive() {return health > 0;}
	string vitals();

	Item getDrop();
};

#endif