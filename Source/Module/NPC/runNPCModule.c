#include "NPC.h"

void runNPCModule(Game *game)
{
    // npc종치기
    if (game->npc->tmpAvgTimeUserPutDownBell < (game->playTime - game->lastTime) && isNiceBellNPC(game) == 1) //종을 잘 쳤을 때
    {
        npcPutDownBell(game, game->npc);
    }

    // npc 카드 내려놓기
    if (game->who == 1 && (game->npc->tmpAvgTimeUserPutDownBell+ 200) < (game->playTime - game->lastTime))
    {
        npcPutDownCard(game);
        game->who = 0;
        // if(game->npc->leftCardSet->root->id == BLOCK||game->npc->rightCardSet->root->id == BLOCK){
        //     game->who=1;
        // }
    }
    //npc 난이도 조절
    //npc 블록아이디 테스트
}