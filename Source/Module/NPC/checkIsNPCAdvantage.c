#include "NPC.h"

int checkIsNPCAdvantage(Game *game)
{
    // advantage가 맞으면 1반환
    //
    if (game->npc->leftCardSet->root->id % 5 == 4 || game->npc->leftCardSet->root->id % 5 == 4)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}