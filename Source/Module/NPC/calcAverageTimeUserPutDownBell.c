#include "NPC.h"

void calcAverageTimeUserPutDownBell(Game *game, NPC *npc)
{
    npc->totalTimeUserPutDownBell += getTimeUserPutDownBell(game);
    npc->avgTimeUserPutDownBell = npc->totalTimeUserPutDownBell / npc->cntUserPutDownBell;
}
