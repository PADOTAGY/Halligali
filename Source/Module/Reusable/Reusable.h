#ifndef reusable_H
# define reusable_H

#include <stdio.h>
#include <stdlib.h>

typedef enum ItemId { RuleChange = 0, Star = 1, Bomb = 2, Win = 3 } ItemId;
typedef enum ItemState { Active = 0, Inactive = 1, Deleted = 2 } ItemState;

typedef struct Item {
	ItemId id;
	ItemState state;
	int roundCount;
} Item;

typedef struct User {
    Item *item;
} User;

typedef struct Game {
	User *user;
}

#endif