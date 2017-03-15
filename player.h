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
#include "equipment.h"
#include "item.h"
#include "equippable.h"
#include "consumable.h"

using namespace std;

class Player {
private:
	string name;
	int age;	
	
	int baseHealth;
	int health;
	int healthBonus;
	int maxHealth;
	
	int baseAttack;
	int attack;
	int attackBonus;

	int baseStrength;
	int strength;
	int strengthBonus;

	int baseDefense;
	int defense;
	int defenseBonus;

	int experience;
	int level;
	int nextLevel;

	Inventory inventory;
	Equipment equipment;
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

	void addToInventory(Item *item);
	void dropItem(int slot);
	void showInventory();

	void showEquipment();

	void useItem(int slot);
	void equip(Equippable *item);
	void unequip(int slot);
	void consume(Consumable *item);

	void boostStats(Equippable *item);
	void reduceStats(Equippable *item);

	void refreshStats();

	void showStats();
};

#endif