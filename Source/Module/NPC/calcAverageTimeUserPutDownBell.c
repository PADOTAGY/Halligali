#include "NPC.h"

void calcAverageTimeUserPutDownBell(Game *game, NPC *npc)
{
    npc->totalTimeUserPutDownBell += getTimeUserPutDownBell(game);
    if (npc->cntUserPutDownBell != 0) //최소 종을 1번은 처야한다.
        npc->tmpAvgTimeUserPutDownBell = npc->totalTimeUserPutDownBell / npc->cntUserPutDownBell;
    npc->avgTimeUserPutDownBell = npc->tmpAvgTimeUserPutDownBell;

    // npc->totalTimeUserPutDownBell : user가 올바르게 종을 쳤을 때, 종을 치는 시간을 모두 더함
    // npc->tmpAvgTimeUserPutDownBell : user가 종을 치는 평균 시간계산 == 난이도 (플레이 도중 값이 바뀜. 난이도 상승시)
    // npc->avgTimeUserPutDownBell : user가 종을 치는 평균 시간 -> UI에 넣는다
}
