#include "../NPC.h"

void updateIsMissPutDownBell(Game *game, NPC *npc)
{
    if (isMissPutDownBell(game, npc))
        npc->isMissPutDownBell = 1;
}

int isMissPutDownBell(Game *game, NPC *npc)
{
    int max = (int)(100 * (1000 / game->sleepMs)); // 10%확률
    // if (game->)
    //     if (1 == 1) // 어떨때 확률 높일지 ?
    //         max = 5;

    if (getRandomInt(0, max) == 0)
        return 1;
    return 0;
}