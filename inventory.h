//
//  inventory.h
//  C++ Playground
//
//  Created by Joseph Wicker on 1/4/17.
//  Copyright © 2017 Cavalier Productions. All rights reserved.
//

#ifndef INVENTORY_H
#define INVENTORY_H

#include <map>
#include "item.h"

class Inventory {
private:
	map <int, Item*> inventory;
	int size;
	bool full;
	int nextFree;
	void findNextFree();

public:
	Inventory();
	bool isFull() {return full;}
	void addItem(Item *item);
	Item* getItem(int slot);
	void dropItem(int slot);
	void showInventory();
};

#endif