//
//  consumable.cpp
//  C++ Playground
//
//  Created by Joseph Wicker on 1/4/17.
//  Copyright © 2017 Cavalier Productions. All rights reserved.
//

#include <string>
#include <iostream>
#include "consumable.h"

using namespace std;

Consumable::Consumable(string name, int levelReq, int healAmount) : Item(name, 2, levelReq), healAmount(healAmount) {

}

string Consumable::toString() {
	return name;
}