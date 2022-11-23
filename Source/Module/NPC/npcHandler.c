#include "NPC.h"

void npcHandler(Game *game){
    //if(종을 치는 조건 만족하면)
        getTimeUserPutDownBell(game);
    npcDrawCard(game);
    calcAverageTimeUserPutDownBell(game, game->npc) ;
}
