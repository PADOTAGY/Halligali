#ifndef ITEM_H
# define ITEM_H

#define RULECHANGE_ITEM_MAX_ROUND 0
#define STAR_ITEM_MAX_ROUND 3
#define BOMB_ITEM_MAX_ROUND 0
#define WIN_ITEM_MAX_ROUND 0

#define UP 72

#include "../Reusable/Reusable.h"

void runItemModule(Game *game, int reset);
Item* getNextItem();
void checkAndRunItem(Item *item);

int isActiveRuleChangeItem(Item *item);
int isActiveStarItem(Item *item);
int isActiveBombItem(Item *item);
int isActiveWinItem(Item *item);

#endif