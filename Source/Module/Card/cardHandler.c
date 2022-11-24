#include "card.h"
void cardHandler(Game *game)
{
    if (game->who == 0)
    {
        switch (game->key)
        {
        case LEFT:
            putDownCard(game->user->originCardSet, game->user->leftCardSet);
            game->who = 1;
            break;

        case RIGHT:
            putDownCard(game->user->originCardSet, game->user->rightCardSet);
            game->who = 1;
            break;

        case SPACE:
            game->whoBell = 0;
            putDownBell(game);
            game->whoBell = -1;
        default:
            break;
        }
    }
    else
    {
        switch (game->key)
        {
        case SPACE:
            game->whoBell = 0;
            putDownBell(game);
            game->whoBell = -1;
        default:
            break;
        }
    }
}