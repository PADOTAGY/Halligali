#include "../item.h"

int isActiveRuleChangeItem(Item *item) {
    if (item->id == RuleChangeItemId && item->state == Active)
        return 1;
    return 0;
}

int isActiveStarItem(Item *item) {
    if (item->id == StarItemId && item->state == Active)
        return 1;
    return 0;
}

int isActiveBombItem(Item *item) {
    if (item->id == BombItemId && item->state == Active)
        return 1;
    return 0;
}

int isWinItem(Game *game, Item *item) {
    if (item->id == WinItemId && item->state == Active)
        return 1;
    return 0;
}