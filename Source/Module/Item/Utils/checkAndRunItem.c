#include "reusable.h"
#include "item.h"

void checkAndRunItem(Item *item) {
    if (item == NULL) return;

    switch(item->state) {
        case Active:
            runItem(item);
            break;

        case Inactive:
            break;
    }
}