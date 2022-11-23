#include "../game.h"

int checkAndRunEndGame(Game *game) {
    updateGameState(game);
    if (isEndGame(game)) {
        if (isWinUser(game))
            game->user->score += 1;
        else
            game->npc->score += 1;
        return 1;
    }
    return 0;
}

void updateGameState(Game *game) {
    if (game->npc->originCardSet->count == 0 || game->user->originCardSet->count == 0)
        game->state = End;
}

int isEndGame(Game *game) {
    if (game->state == End)
        return 1;
    return 0;
}

int isWinUser(Game *game)
{
    if (game->npc->originCardSet->count == 0)
        return 1;
    else
        return 0;
}
