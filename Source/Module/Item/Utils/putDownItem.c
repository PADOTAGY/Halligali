#include "../item.h""

void putDownItem(User *user, Item *item) {
    if (item == NULL) return;

    switch (item->state) {
        case Active:
            break;

        case Inactive:
            user->item->round = 0;
            runItem(item);
            break;
    }
    runItem(item);
}
