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

using namespace std;

Player::Player(string name, int age) {
	this->name = name;
	this->age = age;

	maxHealth = 150;
	health = maxHealth;
	
	attack = 10;
	strength = 10;
	defense = 10;

	experience = 0;
	level = 1;
	nextLevel = pow(2, (level + 2));

	inv = Inventory();
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
	
	int skillPoint = 1;

	while (skillPoint > 0) {
		int pChoice;
		cout << "You have " << skillPoint << " skill point(s) to spend! What would you like to level up?" << endl;
		cout << "[1:Attack], [2:Strength], [3:Defense], [4:Health]" << endl;
		cin >> pChoice;

		switch (pChoice) {
			case 1:
				attack++;
				skillPoint--;
				cout << "You chose to add 1 point to Attack. Your Attack is now " << attack << "." << endl;
				break;
			case 2:
				strength++;
				skillPoint--;
				cout << "You chose to add 1 point to Strength. Your Strength is now " << strength << "." << endl;
				break;
			case 3:
				defense++;
				skillPoint--;
				cout << "You chose to add 1 point to Defense. Your Defense is now " << defense << "." << endl;
				break;
			case 4:
				maxHealth += 5;
				skillPoint--;
				cout << "You chose to add 1 point to Health. You Max Health is now " << maxHealth << "." << endl;
				break;
			default:
				cout << "Oops, try again." << endl << endl;
		}
	}
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

void Player::addToInventory(Item item) {
	inv.addItem(item);
}

void Player::showInventory() {
	inv.showInv();
}