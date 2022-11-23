#include<NPC.h>

int checkIsNPCAdvantage()
{
    if(game->npc.leftCardSet->root.id%5==4||game->npc.leftCardSet->root.id%5==4)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}