#include "reusable.h"
#include "item.h"

Item* getNextItem() {
    Item *item = (Item*)malloc(sizeof(Item));

    return item;
}