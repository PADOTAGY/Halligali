#include "../item.h"

void runItem(Game *game, Item *item) {
    if (item == NULL) return;

    item->drawCnt += 1;
    
    updateItemState(item);
    
    if (item->state != Active) return;

    switch (item->id) {
        case RuleChangeItemId:
            ruleChangeItemHandler(game, item);
            break;

        case StarItemId:
            starItemHandler(game, item);
            break;

        case BombItemId:
            bombItemHandler(game, item);
            break;

        case WinItemId:
            winItemHandler(game, item);
            break;
    }
}

void updateItemState(Item *item) {
    item->state = Active;

    switch (item->id) {
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

void ruleChangeItemHandler(Game *game, Item *item) {
    
}

void starItemHandler(Game *game, Item *item) {

}

void bombItemHandler(Game *game, Item *item) {

}

void winItemHandler(Game *game, Item *item) {

}