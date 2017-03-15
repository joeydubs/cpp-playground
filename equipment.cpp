//
//  equipment.h
//  C++ Playground
//
//  Created by Joseph Wicker on 1/4/17.
//  Copyright © 2017 Cavalier Productions. All rights reserved.
//

#include <iostream>
#include <string>
#include "equipment.h"

using namespace std;

Equipment::Equipment() {
	
}

void Equipment::equip(Equippable *item) {
	int itemSlot = item -> getSlot();

	equipment.insert({itemSlot, item});
}

Equippable* Equipment::unequip(int slot) {
	Equippable *item = equipment.at(slot);
	equipment.erase(slot);
	return item;
}

bool Equipment::isOccupied(int slot) {
	if (equipment.count(slot)) {
		return true;
	}

	return false;
}

void Equipment::showEquipment() {
	for (int i = 1; i <= 5; i++) {
		if (equipment.count(i)) {
			cout << "Slot " << i << ": " << equipment.at(i) -> toString() << endl;
		}
		else {
			cout << "Slot " << i << ": Empty" << endl;
		}
	}

	cout << endl;
}