//
//  item.cpp
//  C++ Playground
//
//  Created by Joseph Wicker on 1/4/17.
//  Copyright © 2017 Cavalier Productions. All rights reserved.
//

#include <string>
#include "item.h"

using namespace std;

Item::Item(string n, int t, int l) : name(n), type(t), levelReq(l) {

}

ostream &operator<<(ostream &out, const Item &item) {
	return out << item.name;
}