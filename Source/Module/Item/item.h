#ifndef ITEM_H
#define ITEM_H

#define RULECHANGE_ITEM_MAX_ROUND 5
#define STAR_ITEM_MAX_ROUND 5
#define BOMB_ITEM_MAX_ROUND 5
#define WIN_ITEM_MAX_ROUND 1

#define UP 72

#include "../Reusable/Reusable.h"

void runItemModule(Game *game);
Item *getNextItem();
void checkAndRunItem(Item *item);

int isActiveItem(Item *item);
int isActiveRuleChangeItem(Item *item);
int isActiveStarItem(Item *item);
int isActiveBombItem(Item *item);
int isActiveWinItem(Item *item);

void updateRandomItem(Game *game);
#endif