#include "item.h"

void runItemModule(Game *game, int reset) {
    if (game->drawCnt % reset) {
        free(game->user->item);
        game->user->item = getNextItem();
    }
    if (game->key == UP) {
        putDownItem(game->user, game->user->item);
    }
    checkAndRunItem(game->user->item);
}

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

void putDownItem(User *user, Item *item) {
    if (item == NULL) return;

    switch (item->state) {
        case Active:
            break;

        case Inactive:
            user->item->drawCnt = 0;
            runItem(item);
            break;
    }
    runItem(item);
}
