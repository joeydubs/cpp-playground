//
//  player.cpp
//  C++ Playground
//
//  Created by Joseph Wicker on 1/4/17.
//  Copyright © 2017 Cavalier Productions. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <cmath>
#include "player.h"
#include "inventory.h"
#include "equipment.h"
#include "equippable.h"
#include "consumable.h"

using namespace std;

Player::Player(string name, int age) : name(name), age(age) {
	baseHealth = 150;
	health = baseHealth;
	healthBonus = 0;
	maxHealth = baseHealth + healthBonus;
	
	baseAttack = 10;
	attack = baseAttack;
	attackBonus = 0;

	baseStrength = 10;
	strength = baseStrength;
	strengthBonus = 0;

	baseDefense = 10;
	defense = baseDefense;
	defenseBonus = 0;

	experience = 0;
	level = 1;
	nextLevel = pow(2, (level + 2));

	Inventory inventory{};
	Equipment equipment{};
}

void Player::setName(string name) {
	this->name = name;
}

void Player::setAge(int age) {
	this->age = age;
}

void Player::addExp(int exp) {
	experience += exp;

	if (experience >= nextLevel) {
		levelUp();
	}

	cout << "Experience: " + to_string(experience) + "/" + to_string(nextLevel) << endl;
}

void Player::levelUp() {
	level++;
	experience %= nextLevel;
	nextLevel = pow(2, (level + 2));
	cout << "You leveled up! You are now level " << level << "." << endl;

	int skillPoint;
	
	if (level < 5) {
		skillPoint = 1;
	}
	else {
		skillPoint = 2;
	}

	while (skillPoint > 0) {
		int pChoice;
		cout << "You have " << skillPoint << " skill point(s) to spend! What would you like to level up?" << endl;
		cout << "[1:Attack], [2:Strength], [3:Defense], [4:Health]" << endl;
		cin >> pChoice;

		switch (pChoice) {
			case 1:
				baseAttack++;
				attack = baseAttack + attackBonus;
				skillPoint--;
				cout << "You chose to add 1 point to Attack. Your Base Attack is now " << baseAttack << "." << endl;
				break;
			case 2:
				baseStrength++;
				strength = baseStrength + strengthBonus;
				skillPoint--;
				cout << "You chose to add 1 point to Strength. Your Base Strength is now " << baseStrength << "." << endl;
				break;
			case 3:
				baseDefense++;
				defense = baseDefense + defenseBonus;
				skillPoint--;
				cout << "You chose to add 1 point to Defense. Your Base Defense is now " << baseDefense << "." << endl;
				break;
			case 4:
				baseHealth += 5;
				health = baseHealth + healthBonus;
				skillPoint--;
				cout << "You chose to add 1 point to Health. You Base Health is now " << baseHealth << "." << endl;
				break;
			default:
				cout << "Oops, try again." << endl << endl;
		}

		cout << endl;
	}

	refreshStats();
}

int Player::dealDamage() {
	int damage = rand() % attack;

	if (damage == 0) {
		return 0;
	}
	else {
		damage += rand() % strength;
	}

	return damage;
}

void Player::takeDamage(int damageDelt) {
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

void Player::heal() {
	health = maxHealth;
}

string Player::vitals() {
	return to_string(health) + "/" + to_string(maxHealth);
}

void Player::addToInventory(Item *item) {
	if (!inventory.isFull()) {
		inventory.addItem(item);
		cout << item -> toString() << " added to inventory." << endl;
	}
	else {
		cout << "Your inventory is full." << endl;
	}
}

void Player::dropItem(int slot) {
	inventory.dropItem(slot);
}

void Player::showInventory() {
	inventory.showInventory();
}

void Player::showEquipment() {
	equipment.showEquipment();
}

void Player::useItem(int slot) {
	Item *item = inventory.getItem(slot);
	cout << "You chose to use the item " << item -> toString() << "." << endl;

	switch (item -> getType()) {
		case 1:
			equip(dynamic_cast<Equippable*>(item));
		break;
		case 2:
			consume(dynamic_cast<Consumable*>(item));
		break;
		default:
			cout << "This item is not a recognized type." << endl;
			addToInventory(item);
	}
}

void Player::equip(Equippable *item) {
	int itemSlot = item -> getSlot();

	if (equipment.isOccupied(itemSlot)) {
		unequip(itemSlot);
	}

	equipment.equip(item);
	boostStats(item);
}

void Player::unequip(int slot) {
	Equippable *item = equipment.unequip(slot);
	reduceStats(item);
	addToInventory(item);
}

void Player::consume(Consumable *item) {
	health += item -> getHealAmount();

	if (health > maxHealth) {
		health = maxHealth;
	}

	cout << "Some health has been restored. Your health is now " << health << "/" << maxHealth << "." << endl;
}

void Player::boostStats(Equippable *item) {
	healthBonus += item -> getHealthBoost();
	attackBonus += item -> getAttackBoost();
	strengthBonus += item -> getStrengthBoost();
	defenseBonus += item -> getDefenseBoost();

	refreshStats();
}

void Player::reduceStats(Equippable *item) {
	healthBonus -= item -> getHealthBoost();
	attackBonus -= item -> getAttackBoost();
	strengthBonus -= item -> getStrengthBoost();
	defenseBonus -= item -> getDefenseBoost();

	refreshStats();
}

void Player::refreshStats() {
	maxHealth = baseHealth + healthBonus;
	if (health > maxHealth) {
		health = maxHealth;
	}

	attack = baseAttack + attackBonus;
	strength = baseStrength + strengthBonus;
	defense = baseDefense + defenseBonus;
}

void Player::showStats() {
	cout << "     Name: " << name << endl;
	cout << "      Age: " << age << endl;
	cout << "   Vitals: " << vitals() << endl << endl;

	cout << "  Base HP: " << baseHealth << endl;
	cout << " HP Bonus: " << healthBonus << endl;
	cout << "   Max HP: " << maxHealth << endl << endl;

	cout << " Base Att: " << baseAttack << endl;
	cout << "   Attack: " << attack << endl;
	cout << "Att Bonus: " << attackBonus << endl << endl;

	cout << " Base Str: " << baseStrength << endl;
	cout << " Strength: " << strength << endl;
	cout << "Str Bonus: " << strengthBonus << endl << endl;

	cout << " Base Def: " << baseDefense << endl;
	cout << "  Defense: " << defense << endl;
	cout << "Def Bonus: " << defenseBonus << endl << endl;

	cout << "    Level: " << level << endl;
	cout << "      Exp: " << experience << endl;
	cout << " Next Lvl: " << nextLevel << endl << endl;
}