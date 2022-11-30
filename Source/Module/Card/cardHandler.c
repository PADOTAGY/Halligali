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
            putDownCard(game->user->originCardSet, game->user->leftCardSet);
            game->who = 1;
            game->drawCnt++;
            game->lastTime = game->playTime;
            if (isActiveItem(game->user->item))
                game->user->item->drawCnt++;
            break;

        case RIGHT:
            putDownCard(game->user->originCardSet, game->user->rightCardSet);
            game->who = 1;
            game->drawCnt++;
            game->lastTime = game->playTime;
            if (isActiveItem(game->user->item))
                game->user->item->drawCnt++;
            break;
        // case 'z':
        //     putDownCard(game->npc->originCardSet, game->npc->leftCardSet);
        //     break;
        // case 'x':
        //     putDownCard(game->npc->originCardSet, game->npc->rightCardSet);
        //     break;
        case SPACE:
            putDownBell(game);
        // case 'c':
        //     game->whoBell = 1;
        //     putDownBell(game);
        //     game->whoBell = -1;
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