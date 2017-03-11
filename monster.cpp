//
//  monster.cpp
//  C++ Playground
//
//  Created by Joseph Wicker on 1/4/17.
//  Copyright © 2017 Cavalier Productions. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "monster.h"
#include "item.h"

using namespace std;

Monster::Monster(string name, int maxHealth) {
	this->name = name;
	this->maxHealth = maxHealth;

	health = maxHealth;
	
	attack = 10;
	strength = 10;
	defense = 10;

	expDrop = maxHealth / 50;
}

int Monster::dealDamage() {
	int damage = rand() % attack;

	if (damage == 0) {
		return 0;
	}
	else {
		damage += rand() % strength;
	}

	return damage;
}

void Monster::takeDamage(int damageDelt) {
	int defenseRoll = rand() % defense;

	if (defenseRoll == defense - 1) {
		damageDelt = 0;
	}
	else {
		damageDelt -= defenseRoll;
		if (damageDelt < 0) {
			damageDelt = 0;
		}
	}

	health -= damageDelt;

	if (health < 0) {
		health = 0;
	}
}

string Monster::vitals() {
	return std::to_string(health) + "/" + std::to_string(maxHealth);
}

Item Monster::getDrop() {
	int slot = rand() % dropTable.size();
	Item drop = dropTable.at(slot);
	return drop;
}