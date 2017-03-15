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
#include "consumable.h"

using namespace std;

class Monster {
private:
	string name;

	int health;
	int maxHealth;

	int attack;
	int strength;
	int defense;
public:
	// Constructor
	Monster(string name, int maxHealth);

	int expDrop;

	string getName() {return name;}

	int dealDamage();
	void takeDamage(int damageDelt);

	bool isAlive() {return health > 0;}
	string vitals();

	Item* getDrop();
};

#endif