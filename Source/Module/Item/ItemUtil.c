#include "item.h"



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
