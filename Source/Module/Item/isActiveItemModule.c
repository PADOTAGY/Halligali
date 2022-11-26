#include "item.h"

int isActiveItem(Item *item)
{
    if (item == NULL)
        return 0;
    if (item->state == Active)
        return 1;
    return 0;
}

int isActiveRuleChangeItem(Item *item)
{
    if (item == NULL)
        return 0;
    if (item->id == RuleChangeItemId && item->state == Active)
        return 1;
    return 0;
}

int isActiveStarItem(Item *item)
{
    if (item == NULL)
        return 0;
    if (item->id == StarItemId && item->state == Active)
        return 1;
    return 0;
}

int isActiveBombItem(Item *item)
{
    if (item == NULL)
        return 0;
    if (item->id == BombItemId && item->state == Active)
        return 1;
    return 0;
}

int isActiveWinItem(Item *item)
{
    if (item == NULL)
        return 0;
    if (item->id == WinItemId && item->state == Active)
        return 1;
    return 0;
}