#include "reusable.h"
#include "item.h"

void putDownItem(Item *item) {
    if (item == NULL) return;

    switch (item->state) {
        case Active:
            break;

        case Inactive:
            runItem(item);
            break;
    }
    runItem(item);
}
