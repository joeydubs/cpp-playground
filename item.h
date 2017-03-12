//
//  item.h
//  C++ Playground
//
//  Created by Joseph Wicker on 1/4/17.
//  Copyright © 2017 Cavalier Productions. All rights reserved.
//

#ifndef ITEM_H
#define ITEM_H

#include <string>

using namespace std;

class Item {
private:
	string name;
	int type;
	int levelReq;
public:
	Item(string name, int type, int levelReq);
	string getName() {return name;}
	int getType() {return type;}
	string toString();
	friend ostream &operator<<(ostream &out, const Item &item);
};

#endif