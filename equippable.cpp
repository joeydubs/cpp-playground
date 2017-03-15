//
//  equippable.cpp
//  C++ Playground
//
//  Created by Joseph Wicker on 1/4/17.
//  Copyright © 2017 Cavalier Productions. All rights reserved.
//

#include <string>
#include <iostream>
#include "equippable.h"

using namespace std;

Equippable::Equippable(string n, int lr, int s, int hb, int ab, int sb, int db) : Item(n, 1, lr), slot(s), healthBoost(hb), attackBoost(ab), strengthBoost(sb), defenseBoost(db) {

}

string Equippable::toString() {
	return name;
}