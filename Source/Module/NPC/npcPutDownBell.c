#include "NPC.h"

void npcPutDownBell(Game *game, NPC *npc)
{

    game->whoBell = 1;

    int countAll = game->user->leftCardSet->count + game->user->rightCardSet->count + game->npc->leftCardSet->count + game->npc->rightCardSet->count;
    if (game->npc->originCardSet->count == 0)
    {
        game->npc->originCardSet->root = mergedCardSet(game);
    }
    else
    {
        struct Card *p = getCard(game->npc->originCardSet, game->npc->originCardSet->count - 1);
        p->next = mergedCardSet(game);
    }
    game->npc->originCardSet->count += countAll;
    if (game->npc->advantage > 0)
    {
        game->npc->advantage = 0;
        returnRaiseDifficultyNPCAdvantage(game);
    }
}