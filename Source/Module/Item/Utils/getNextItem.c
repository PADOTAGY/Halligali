#include "../item.h"

ItemId getRandomItem() {
    switch (getRandomInt(0, 4)) {
        case 0:
            return RuleChangeItemId;
        case 1:
            return StarItemId;
        case 2:
            return BombItemId;
        case 3:
            return WinItemId;
        default:
            return RuleChangeItemId;
    }
}

Item* getNextItem() {
    Item *item = (Item*)malloc(sizeof(Item));
    item->id = getRandomItem();
    // item->id = 0;
    item->state = Inactive;
    item->drawCnt = 0;

    return item;
}

int getRandomInt(int start, int end) {
    srand(time(NULL));
    
    return rand() % (end - start + 1) + start;
}