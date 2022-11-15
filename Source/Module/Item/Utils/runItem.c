#include "../item.h"

void runItem(Game *game, Item *item) {
    if (item == NULL) return;

    item->round += 1;
    
    updateItemState(item);
    
    if (item->state != Active) return;

    switch (item->id) {
        case RuleChange:
            ruleChangeItemHandler(game, item);
            break;

        case Star:
            starItemHandler(game, item);
            break;

        case Bomb:
            bombItemHandler(game, item);
            break;

        case Win:
            winItemHandler(game, item);
            break;
    }
}

void updateItemState(Item *item) {
    item->state = Active;

    switch (item->id) {
        case RuleChange:
            if (item->round > RULECHANGE_ITEM_MAX_ROUND)
                item->state = Deleted;
            break;

        case Star:
            if (item->round > STAR_ITEM_MAX_ROUND)
                item->state = Deleted;
            break;

        case Bomb:
            if (item->round > BOMB_ITEM_MAX_ROUND)
                item->state = Deleted;
            break;

        case Win:
            if (item->round > WIN_ITEM_MAX_ROUND)
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