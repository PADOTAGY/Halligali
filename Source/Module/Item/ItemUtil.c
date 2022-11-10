#include "Reusable.h"
#include "ItemModule.h"

Item* getNextItem() {
    Item *item = (Item *)malloc(sizeof(Item));

    return item;
}

void checkAndRunItem(Item *item) {
    if (item == NULL) return;

    switch(item->state) {
        case Active:
            runItem(item);
            break;

        default: 
            break;
    }
}

void putDownItem(Item *item) {
    if (item == NULL) return;

    switch (item->state) {
        case Inactive:
            runItem(item);
            break;

        default:
            break;
    }
    runItem(item);
}

// Inner Function

void runItem(Item *item) {
    if (item == NULL) return;

    switch (item->id) {
        case RuleChange:
            ruleChangeItemHandler();
        case Star:
            starItemHandler();
        case Bomb:
            bombItemHandler();
            break;
        case Win:
            winItemHandler();
            break;
    }
}

void ruleChangeItemHandler() {

}

void starItemHandler() {

}

void bombItemHandler() {

}

void winItemHandler() {

}