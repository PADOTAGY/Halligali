#include "NPC.h"

void runNPCModule(Game *game)
{
    //npc종치기
    if (isNiceBell(game)) //종을 잘 쳤을 때
    {
        npcPutDownBell(game,game->npc);
    }
    missPutDownBell(game, game->npc);

    //npc 카드 내려놓기
    if(game->who==1)
    {
        npcPutDownCard(game);
        game->who=0;
    }
    calcAverageTimeUserPutDownBell(game, game->npc);
}