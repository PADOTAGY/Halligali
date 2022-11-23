#ifndef user_H
# define user_H

#include "../module.h"

typedef struct User {
    CardSet *originCardSet;
    CardSet *leftCardSet;
    CardSet *rightCardSet;
    Item *item;
    int point;
} User;

#endif