#include "NPC.h"

void calcAverageTimeUserPutDownBell(Game *game, NPC *npc) 
{
    npc->totalTimeUserPutDownBell += getTimeUserPutDownBell(game);
    npc->AvgTimeUserPutDownBell = npc->totalTimeUserPutDownBell / npc->cntUserPutDownBell;
}
