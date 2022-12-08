#include "card.h"
void cardHandler(Game *game)
{
    if (game->who == 0)
    {
        if (game->user->originCardSet->count == 0)
        {
            game->who = 1;
        }
        switch (game->key)
        {
        case LEFT:
            if (game->user->leftCardSet->root->id == BLOCK)
            {
                break;
            }
            putDownCard(game->user->originCardSet, game->user->leftCardSet);
            game->who = 1;
            game->drawCnt++;
            game->lastTime = game->playTime;
            if (isActiveItem(game->user->item))
                game->user->item->drawCnt++;
            break;

        case RIGHT:
            if (game->user->rightCardSet->root->id == BLOCK)
            {
                break;
            }
            putDownCard(game->user->originCardSet, game->user->rightCardSet);
            game->who = 1;
            game->drawCnt++;
            game->lastTime = game->playTime;
            if (isActiveItem(game->user->item))
                game->user->item->drawCnt++;
            break;
        case SPACE:
            putDownBell(game);
        default:
            break;
        }
    }
    else
    {
        switch (game->key)
        {
        case SPACE:
            putDownBell(game);
        default:
            break;
        }
    }
}