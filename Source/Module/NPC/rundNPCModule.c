#include "NPC.h"

void runNPCModule(Game *game)
{
    updateIsMissPutDownBell(game, game->npc);
    putDownBell(game);
    npcDrawCard(game);
    calcAverageTimeUserPutDownBell(game, game->npc);
}