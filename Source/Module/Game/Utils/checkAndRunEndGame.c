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
    game->whoBell = -1;
    return 0;
}

void updateGameState(Game *game) {      // 카드수 둘다 0이거나  
    if (((game->whoBell!=-1) && (npc->originCardSet->count == 0 || game->user->originCardSet->count == 0)) || (npc->originCardSet->count == 0 && game->user->originCardSet->count == 0))
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
