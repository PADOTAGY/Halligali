#include "NPC.h"

void runNPCModule(Game *game)
{
    // npc종치기
    if (game->npc->tmpAvgTimeUserPutDownBell < (game->playTime - game->lastTime) && isNiceBell(game) == 1) //종을 잘 쳤을 때
    {
        npcPutDownBell(game, game->npc);
    }
    // missPutDownBell(game, game->npc);

    // npc 카드 내려놓기
    if (game->who == 1 && getTimeWhenNPCDrawCard() < (game->playTime - game->lastTime))
    {
        npcPutDownCard(game);
        game->who = 0;
    }
}