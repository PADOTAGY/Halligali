#include "card.h"
void cardHandler(Game *game)
{
    if (game->who == 0)
    {
        switch (game->key)
        {
        case LEFT:
            putDownCard(game->user->originCardSet, game->user->leftCardSet);
            // game->who = 1;
            break;

        case RIGHT:
            putDownCard(game->user->originCardSet, game->user->rightCardSet);
            // game->who = 1;
            break;
        case 'z':
            putDownCard(game->npc->originCardSet, game->npc->leftCardSet);
            break;
        case 'x':
            putDownCard(game->npc->originCardSet, game->npc->rightCardSet);
            break;
        case SPACE:
            game->whoBell = 0;
            putDownBell(game);
            game->whoBell = -1;
        case 'c':
            game->whoBell = 1;
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