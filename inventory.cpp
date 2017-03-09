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

void Inventory::addItem(Item item) {
	if (!full) {
		inventory[nextFree] = item;
		findNextFree();
	}
	else {
		cout << "Your inventory is full (Inv::addItem)";
	}
}

Item Inventory::getItem(int slot) {
	Item item = inventory.at(slot);
	inventory.erase(slot);
	full = false;

	if (nextFree > slot) {
		nextFree = slot;
	}

	return item;
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

void Inventory::showInv() {
	for (int i = 1; i <= size; i++) {
		if (inventory.count(i)) {
			if (i < 10) {
				cout << "Slot  " << i << ": " << inventory.at(i) << endl;
			}
			else {
				cout << "Slot " << i << ": " << inventory.at(i) << endl;

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
}