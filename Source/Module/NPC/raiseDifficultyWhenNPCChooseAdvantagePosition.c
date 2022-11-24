#include "NPC.h"

void raiseDifficultyNPCAdvantage(Game *game)
{
    game->npc->tmpAvgTimeUserPutDownBell = game->npc->avgTimeUserPutDownBell;
    game->npc->avgTimeUserPutDownBell *= 0.3; //난이도 상승
}

void returnRaiseDifficultyNPCAdvantage(Game *game)
{
    game->npc->avgTimeUserPutDownBell = game->npc->avgTimeUserPutDownBell / 3 * 10; //난이도 원상태로
}
