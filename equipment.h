//
//  equipment.h
//  C++ Playground
//
//  Created by Joseph Wicker on 1/4/17.
//  Copyright © 2017 Cavalier Productions. All rights reserved.
//

#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include <map>
#include "item.h"
#include "equippable.h"

class Equipment {
private:
	map <int, Equippable*> equipment;
public:
	Equipment();

	void equip(Equippable *item);
	Equippable* unequip(int slot);

	bool isOccupied(int slot);

	void showEquipment();
};

#endif