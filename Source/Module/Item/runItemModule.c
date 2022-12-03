#include "item.h"

void runItemModule(Game *game)  {
    // if (game->drawCnt % 10 == 0 && (game->user->item == NULL || game->user->item->state == Deleted))
    // {
    //     free(game->user->item);
    //     game->user->item = getNextItem();
    // }
    if (game->key == UP)
    {
        putDownItem(game->user, game->user->item);
    }
    updateItemState(game->user->item);
}

void updateRandomItem(Game *game) {
    free(game->user->item);
    game->user->item = getNextItem();
}