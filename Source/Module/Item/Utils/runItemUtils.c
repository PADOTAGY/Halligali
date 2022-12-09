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
        if (item->drawCnt >= 5)
            item->state = Deleted;
        break;

    case StarItemId:
        if (item->drawCnt >= 5)
            item->state = Deleted;
        break;

    case BombItemId:
        item->state = Active;
        if (item->drawCnt >= 3)
            item->state = Deleted;
        break;

    case WinItemId:
        if (item->drawCnt >= 1)
            item->state = Deleted;
        break;
    }
}