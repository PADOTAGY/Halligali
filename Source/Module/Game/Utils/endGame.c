#include "Card.h"
#include "Reusable.h"

int isEnd()
{
    if (game->npc.originCardSet->count == 0 || game->user.originCardSet->count == 0)
    {
        endGame();
        return 1;
    }
    else
    {
        return 0;
    }
}

int whoIsWinner()
{
    if (game->npc.originCardSet->count == 0)
    {
        return 0; //user = 0
    }
    else
    {
        return 1; //npc = 1
    }
}

void endGame()
{
    int winner;
    winner = whoIsWinner();
    if (winner == 0)
    {
        game->user.point++;
    }
    else
    {
        game->npc.point++;
    }
    game->gameCnt++;
    readyGameboard();
}
