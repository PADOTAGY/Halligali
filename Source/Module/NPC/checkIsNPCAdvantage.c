#include "NPC.h"

int checkIsNPCAdvantage(Game *game)
{
    // // advantage가 맞으면 1반환 (게임판에 user딸기5 , npc딸기1,2,3,4,5 놓여있으며 npc턴일 때)
    // if (game->user->leftCardSet->root->id % 5 == 4 || game->user->rightCardSet->root->id % 5 == 4) // user카드수5일때
    // {
    //     // for (int i = 0; i < 5; i++)
    //     // {
    //     //     if (game->user->leftCardSet->root->id - i == game->npc->leftCardSet->root->id)
    //     //         return 1;
    //     //     if (game->user->leftCardSet->root->id - i == game->npc->rightCardSet->root->id)
    //     //         return 1;
    //     //     if (game->user->rightCardSet->root->id - i == game->npc->leftCardSet->root->id)
    //     //         return 1;
    //     //     if (game->user->rightCardSet->root->id - i == game->npc->rightCardSet->root->id)
    //     //         return 1;
    //     // }
    //     if (game->user->leftCardSet->root->id / 5 == game->npc->leftCardSet->root->id / 5 || game->user->rightCardSet->root->id / 5 == game->npc->rightCardSet->root->id / 5)
    //         return 1;

    //     return 0;
    // }
    // else
    // {
    //     return 0;
    // }
    int userLeftCard = game->user->leftCardSet->root->id, userRightCard = game->user->rightCardSet->root->id;
    int npcLeftCard = game->npc->leftCardSet->root->id, npcRightCard = game->npc->rightCardSet->root->id;
    if (userLeftCard % 5 == 4) // user 왼쪽카드 숫자가 5일때
    {
        if (userLeftCard / 5 != userRightCard / 5)
        {
            if (userLeftCard / 5 == npcLeftCard / 5 && userLeftCard / 5 != npcRightCard / 5)
            {
                return 1; //왼쪽
            }
            else if (userLeftCard / 5 != npcLeftCard / 5 && userLeftCard / 5 == npcRightCard / 5)
            {
                return 2; //오른쪽
            }
        }
    }
    else if (userRightCard % 5 == 4)
    {
        return 0;
        if (userLeftCard / 5 != userRightCard / 5)
        {
            if (userRightCard / 5 == npcLeftCard / 5 && userRightCard / 5 != npcRightCard / 5)
            {
                return 1; //왼쪽
            }
            else if (userRightCard / 5 != npcLeftCard / 5 && userRightCard / 5 == npcRightCard / 5)
            {
                return 2; //오른쪽
            }
        }
    }
    return 0;
}
