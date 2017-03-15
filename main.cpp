//
//  main.cpp
//  C++ Playground
//
//  Created by Joseph Wicker on 1/4/17.
//  Copyright © 2017 Cavalier Productions. All rights reserved.
//
//  c++ main.cpp player.cpp monster.cpp -o project

#include <iostream>
#include <cstdlib>
#include <sstream>
#include "player.h"
#include "monster.h"

// Allows std functions to be used in an unqualified manner. ie. 'cout' instead of std::cout'
using namespace std;

void fight(Player *player) {
	srand(time(0));

	Monster monster("Goblin", 150);

	int round = 1;

	cout << "You encountered a " << monster.getName() << "!" << endl;

	do {
		//cout << "Round " << round << ": Player Vitals - " << player -> vitals() << "	Monster Vitals - " << monster.vitals() << endl;
		int pDamage = player -> dealDamage();
		monster.takeDamage(pDamage);

		if (monster.isAlive()) {
			int mDamage = monster.dealDamage();
			player -> takeDamage(mDamage);

		}
		else {
			cout << "You slew the " << monster.getName() << "!" << endl;
			cout << "Player Vitals - " << player -> vitals() << endl;
			player -> addToInventory(monster.getDrop());
			player -> addExp(monster.expDrop);
		}

		round++;
	}
	while (player -> isAlive() && monster.isAlive());

	if (!player -> isAlive()) {
		cout << "You have been killed by the " << monster.getName() << "." << endl;
	}
}

void play(Player *player) {
	bool playing = true;
	bool viewInv = false;
	bool viewEqu = false;

	while (playing) {
		int pChoice;

		cout << "Home --> What would you like to do?" << endl;
		cout << "[1:Adventure], [2:Heal], [3:View Inventory], [4:View Equipment], [5:View Stats], [6:Quit]" << endl;

		cin >> pChoice;

		cout << endl;

		switch (pChoice) {
			case 1:
				cout << "Adventure!" << endl;
				fight(player);
			break;
			case 2:
				cout << "Heal" << endl;
				player -> heal();
				cout << "Player vitals: " << player->vitals() << endl;
			break;
			case 3:
				cout << "View Inventory" << endl;
				viewInv = true;
				player -> showInventory();
				while (viewInv) {
					cout << "Inventory --> What would you like to do?" << endl;
					cout << "[1:Use Item], [2:Drop Item], [3:Return]" << endl;
					cin >> pChoice;
					cout << endl;
					switch (pChoice) {
						case 1:
							cout << "You chose to USE an item, which item would you like to use? [0 to cancel]" << endl;
							cin >> pChoice;
							cout << endl;
							if (pChoice == 0) {
								cout << "You chose to cancel." << endl;
							}
							else if (pChoice > 0 && pChoice < 29) {
								player -> useItem(pChoice);
								cout << "\nView Inventory" << endl;
								player -> showInventory();
							}
							else {
								cout << "You choice was outside the inventory's bounds, please try again." << endl;
							}
						break;
						case 2:
							cout << "You chose to DROP an item, which item would you like to DROP? [0 to cancel]" << endl;
							cin >> pChoice;
							cout << endl;
							if (pChoice == 0) {
								cout << "You chose to cancel." << endl;
							}
							else if (pChoice > 0 && pChoice < 29) {
								player -> dropItem(pChoice);
								cout << "\nView Inventory" << endl;
								player -> showInventory();
							}
							else {
								cout << "You choice was outside the inventory's bounds, please try again." << endl;
							}

						break;
						case 3:
							cout << "You chose to exit the inventory view, returning to Home." << endl;
							viewInv = false;
						break;
						default:
							cout << "Oops! Try again with a number relating to the option you would like to pick." << endl;

					}
				};
			break;
			case 4:
				cout << "View Equipment" << endl;
				viewEqu = true;
				player -> showEquipment();
				while (viewEqu) {
					cout << "Equipment --> What would you like to do?" << endl;
					cout << "[1:Unequip Item], [2:Return]" << endl;
					cin >> pChoice;
					cout << endl;
					switch (pChoice) {
						case 1:
							cout << "You chose to unequip an item, which item would you like to unequip? [0 to cancel]" << endl;
							cin >> pChoice;
							cout << endl;
							if (pChoice == 0) {
								cout << "You chose to cancel." << endl;
							}
							else if (pChoice > 0 && pChoice < 6) {
								player -> unequip(pChoice);
								cout << "\nView Equipment" << endl;
								player -> showEquipment();
							}
							else {
								cout << "You choice was outside the equipment's bounds, please try again." << endl;
							}
						break;
						case 2:
							cout << "You chose to exit the equipment view, returning to Home." << endl;
							viewEqu = false;
						break;
						default:
							cout << "Oops! Try again with a number relating to the option you would like to pick." << endl;
					}
				}
			break;
			case 5:
				cout << "View Stats" << endl;
				player -> showStats();
			break;
			case 6:
				cout << "Quit" << endl;
				playing = false;
			break;
			default:
				cout << "Oops! Try again with a number relating to the option you would like to pick." << endl;
		}

		cout << endl << endl << endl;
	}
}

int main() {
	string myString;
	string name;
	int age;
	
	cout << "\n\n\n";

	cout << "Welcome!" << endl << "Please enter your name: ";
	getline(cin, name);
	cout << "Enter your age: ";
	getline(cin, myString);
	stringstream (myString) >> age;

	cout << "\n\n\n";

	Player player(name, age);

	play(&player);

	cout << "Thank you for playing!" << endl;
}