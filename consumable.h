//
//  consumable.h
//  C++ Playground
//
//  Created by Joseph Wicker on 1/4/17.
//  Copyright © 2017 Cavalier Productions. All rights reserved.
//

#ifndef CONSUMABLE_H
#define CONSUMABLE_H

#include <string>
#include "item.h"

using namespace std;

class Consumable : public Item {
private:
	int healAmount;
public:
	Consumable(string name, int levelReq, int healAmount);
	string toString();
	int getHealAmount() {return healAmount;}
};

#endif