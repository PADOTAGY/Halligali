#include "Card.h"
#include "Reusable.h"
int isEndGame()
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
        return USER;
    }
    else
    {
        return NPC;
    }
}
void endGame()
{
    int winner;
    winner = whoIsWinner();
    if (winner == USER)
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