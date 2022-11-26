#include "../NPC.h"

void missPutDownBell(Game *game, NPC *npc)
{
    if (isMissPutDownBell(game, npc))
        penaltyNPC(game);
}

int isMissPutDownBell(Game *game, NPC *npc)
{
    int max = (int)(100 * (1000 / game->sleepMs)); // 10%확률
    int cntOriginCardNPC = npc->originCardSet->count;
    int cntOriginCardUser = game->user->originCardSet->count;

    //카드 수 차이로 난이도 조절.  sleepMs값이 커지면 npc가 실수로 종치는 확률 커진다.
    if(cntOriginCardNPC==cntOriginCardUser) //npc, user의 카드 수 같을 경우
    {
        game->sleepMs=1;
    }
    else if(cntOriginCardNPC-cntOriginCardUser>15) //npc가 user보다 카드 많을 경우
    {
        game->sleepMs=5;
    }
    else if (cntOriginCardUser-cntOriginCardNPC>15) //npc가 user보다 카드 적을 경우
    {
        game->sleepMs=0.2;
    }
    

    if (getRandomInt(0, max) == 0)
        return 1;
    return 0;
}