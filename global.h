//
//  global.h
//  C++ Playground
//
//  Created by Joseph Wicker on 1/4/17.
//  Copyright © 2017 Cavalier Productions. All rights reserved.
//
//

#include <array>
#include "item.h"
#include "consumable.h"
#include "equippable.h"

// Equippable(string n, int lr, int s, int hb, int ab, int sb, int db)
// Consumable(string name, int levelReq, int healAmount)

/* Slots:
	1 - head
	2 - main hand
	3 - chest
	4 - off hand
	5 - legs
*/
     // Equippable			name			lr	s	hb	ab	sb	db
	Equippable someSword{		"Some Sword",		1,	2,	0,	1,	1,	0};
	Equippable someShield{		"Some Shield",		1, 	4,	0,	0,	0,	2};
	Equippable someHelmet{		"Some Helmet",		1, 	1,	0,	0,	0,	1};
	Equippable someChestplate{	"Some Chestplate",	1, 	3,	25,	0,	0,	2};
	Equippable somePlatelegs{	"Some Platelegs",	1, 	5,	0,	0,	0,	1};
	Equippable someOffhand{		"Some Off-Hand Weapon",	1, 	4,	0,	1,	0,	1};

     // Consumable			name				levelReq	healAmount
	Consumable healthPotion{	"Health Potion (100hp)",	1, 		100};

array <Item*, 7> dropTable {
	&someSword,
	&someShield,
	&someHelmet,
	&someChestplate,
	&somePlatelegs,
	&someOffhand,
	&healthPotion
};
