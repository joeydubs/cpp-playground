//
//  inventory.cpp
//  C++ Playground
//
//  Created by Joseph Wicker on 1/4/17.
//  Copyright © 2017 Cavalier Productions. All rights reserved.
//

#include <iostream>
#include <string>
#include "inventory.h"
#include "item.h"

using namespace std;

Inventory::Inventory() {
	full = false;
	nextFree = 1;
	size = 28;
}

void Inventory::addItem(Item *item) {
	if (!full) {
		inventory.insert({nextFree, item});
		findNextFree();
	}
	else {
		cout << "Your inventory is full (Inventory::addItem)";
	}
}

Item* Inventory::getItem(int slot) {
	Item *item = inventory.at(slot);
	inventory.erase(slot);
	full = false;

	if (nextFree > slot) {
		nextFree = slot;
	}

	return item;
}

void Inventory::dropItem(int slot) {
	cout << inventory.at(slot) -> toString() << " is being dropped." << endl;
	inventory.erase(slot);
	full = false;

	if (nextFree > slot) {
		nextFree = slot;
	}
}

void Inventory::findNextFree() {
	nextFree++;

	if (nextFree == size + 1) {
		full = true;
	}
	else if (inventory.count(nextFree)) {
		findNextFree();
	}
}

void Inventory::showInventory() {
	for (int i = 1; i <= size; i++) {
		if (inventory.count(i)) {
			if (i < 10) {
				cout << "Slot  " << i << ": " << inventory.at(i) -> toString() << endl;
			}
			else {
				cout << "Slot " << i << ": " << inventory.at(i) -> toString() << endl;

			}
		}
		else {
			if (i < 10) {
				cout << "Slot  " << i << ": Empty" << endl;
			}
			else {
				cout << "Slot " << i << ": Empty" << endl;
			}
		}
	}

	cout << endl;
}