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
#include "item.h"

// Allows std functions to be used in an unqualified manner. ie. 'cout' instead of std::cout'
using namespace std;

void fight(Player *player) {
	srand(time(0));

	Monster monster("Goblin", 150);

	int round = 1;

	do {
		int pDamage = player -> dealDamage();
		cout << "Player damage round " << round << ": " << pDamage << endl;
		monster.takeDamage(pDamage);
		cout << "Monster vitals: " << monster.vitals() << endl;

		if (monster.isAlive()) {
			int mDamage = monster.dealDamage();
			cout << "Monster damage round " << round << ": " << mDamage << endl;
			player -> takeDamage(mDamage);
			cout << "Player vitals: " << player -> vitals() << endl;
		}
		else {
			cout << "You slew the " << monster.getName() << "!" << endl << endl;
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

	while (playing) {
		int pChoice;

		cout << "What would you like to do?" << endl;
		cout << "[1:Adventure], [2:Heal], [3:Show Inventory], [4:Quit]" << endl;

		cin >> pChoice;

		switch (pChoice) {
			case 1:
				cout << "You chose Adventure!" << endl;
				fight(player);
			break;
			case 2:
				cout << "You chose Heal!" << endl;
				player -> heal();
				cout << "Player vitals: " << player->vitals() << endl;
			break;
			case 3:
				cout << "You chose See Inventory" << endl;
				player -> showInventory();
				cout << "Using item in slot 1:" << endl;
				player -> useItem();
				cout << "Showing inventory again" << endl;
				player -> showInventory();
			break;
			case 4:
				cout << "You chose Quit!" << endl;
				playing = false;
			break;
			default:
				cout << "Oops! Try again!" << endl;
		}

		cout << endl;
	}
}

int main() {
	string myString;
	string name;
	int age;
	
	cout << "Welcome!" << endl << "Please enter your name: ";
	getline(cin, name);
	cout << "Enter your age: ";
	getline(cin, myString);
	stringstream (myString) >> age;

	cout << "\n\n\n";

	Player player(name, age);

	Item item("Some Sword", 1, 1);

	player.addToInventory(item);

	play(&player);

	cout << "Thank you for playing! Player final vitals were " << player.vitals() << endl;
}