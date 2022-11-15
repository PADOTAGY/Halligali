#ifndef item_H
# define item_H

#include "../module.h"

#define RULECHANGE_ITEM_MAX_ROUND 0
#define STAR_ITEM_MAX_ROUND 3
#define BOMB_ITEM_MAX_ROUND 0
#define WIN_ITEM_MAX_ROUND 0

Item* getNextItem();
void checkAndRunItem(Item *item);
void putDownItem(Item *item);

typedef enum ItemId { RuleChange = 0, Star = 1, Bomb = 2, Win = 3 } ItemId;
typedef enum ItemState { Active = 0, Inactive = 1, Deleted = 2 } ItemState;

typedef struct Item {
	ItemId id;
	ItemState state;
	int round;
} Item;

#endif