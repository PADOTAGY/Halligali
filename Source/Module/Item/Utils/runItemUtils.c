#include "../item.h"

void putDownItem(User *user, Item *item)
{
    if (user == NULL || item == NULL)
        return;
    switch (item->state)
    {
    case Active:
        break;

    case Inactive:
        user->item->state = Active;
        user->item->drawCnt = 0;
        updateItemState(item);
        break;
    }
}

void updateItemState(Item *item)
{
    if (item == NULL)
        return;

    switch (item->id)
    {
    case RuleChangeItemId:
        if (item->drawCnt > RULECHANGE_ITEM_MAX_ROUND)
            item->state = Deleted;
        break;

    case StarItemId:
        if (item->drawCnt > STAR_ITEM_MAX_ROUND)
            item->state = Deleted;
        break;

    case BombItemId:
        if (item->drawCnt > BOMB_ITEM_MAX_ROUND)
            item->state = Deleted;
        break;

    case WinItemId:
        if (item->drawCnt > WIN_ITEM_MAX_ROUND)
            item->state = Deleted;
        break;
    }
}