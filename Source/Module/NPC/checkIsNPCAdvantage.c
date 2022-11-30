#include "NPC.h"

int checkIsNPCAdvantage(Game *game)
{
    // advantage가 맞으면 1반환 (게임판에 user딸기5 , npc딸기1,2,3,4,5 놓여있으며 npc턴일 때)
    int userLeftCard = game->user->leftCardSet->root->id, userRightCard = game->user->rightCardSet->root->id;
    int npcLeftCard = game->npc->leftCardSet->root->id, npcRightCard = game->npc->rightCardSet->root->id;
    if (userLeftCard % 5 == 4) // user 왼쪽카드 숫자가 5일때
    {
        if (userLeftCard / 4 != userRightCard / 4)
        {
            if (userLeftCard / 4 == npcLeftCard / 4 && userLeftCard / 4 != npcRightCard / 4)
            {
                return 1; //왼쪽
            }
            else if (userLeftCard / 4 != npcLeftCard / 4 && userLeftCard / 4 == npcRightCard / 4)
            {
                return 2; //오른쪽
            }
        }
    }
    else if (userRightCard % 5 == 4)
    {
        if (userLeftCard / 4 != userRightCard / 4)
        {
            if (userRightCard / 4 == npcLeftCard / 4 && userRightCard / 4 != npcRightCard / 4)
            {
                return 1; //왼쪽
            }
            else if (userRightCard / 4 != npcLeftCard / 4 && userRightCard / 4 == npcRightCard / 4)
            {
                return 2; //오른쪽
            }
        }
    }
    return 0;
}