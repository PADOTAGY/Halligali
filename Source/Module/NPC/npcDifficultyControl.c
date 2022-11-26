#include "NPC.h"

void raiseDifficultyNPCAdvantage(NPC *npc)
{
    npc->tmpAvgTimeUserPutDownBell *= 0.3; //난이도 상승
}

void returnRaiseDifficultyNPCAdvantage(NPC *npc)
{
    npc->tmpAvgTimeUserPutDownBell = npc->tmpAvgTimeUserPutDownBell / 3 * 10; //난이도 원상태로
}
