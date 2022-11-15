#include "reusable.h"
#include "item.h"

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