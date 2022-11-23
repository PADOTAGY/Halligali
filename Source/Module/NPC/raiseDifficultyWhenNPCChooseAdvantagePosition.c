#include "NPC.h"

void raiseDifficultyNPCAdvantage(Game *game){
    game->npc->tmpAvgTimeUserPutDownBell = game->npc->AvgTimeUserPutDownBell;
    game->npc->AvgTimeUserPutDownBell *= 0.3; //난이도 상승
}

void returnRaiseDifficultyNPCAdvantage(Game *game){
    game->npc->AvgTimeUserPutDownBell=game->npc->AvgTimeUserPutDownBell/3*10 ; //난이도 원상태로
}
