//
//  equippable.h
//  C++ Playground
//
//  Created by Joseph Wicker on 1/4/17.
//  Copyright © 2017 Cavalier Productions. All rights reserved.
//

#ifndef EQUIPPABLE_H
#define EQUIPPABLE_H

#include <string>
#include "item.h"

using namespace std;

class Equippable : public Item {
private:
	int slot;
	int healthBoost;
	int attackBoost;
	int strengthBoost;
	int defenseBoost;
public:
	Equippable(string n, int lr, int s, int hb, int ab, int sb, int db);

	int getSlot() {return slot;}

	int getHealthBoost() {return healthBoost;}
	int getAttackBoost() {return attackBoost;}
	int getStrengthBoost() {return strengthBoost;}
	int getDefenseBoost() {return defenseBoost;}

	string toString();
};

#endif