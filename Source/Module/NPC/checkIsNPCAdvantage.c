#include "NPC.h"

int checkIsNPCAdvantage(Game *game)
{
    // advantage가 맞으면 1반환 (게임판에 user딸기5 , npc딸기1,2,3,4,5 놓여있으며 npc턴일 때)
    if (game->user->leftCardSet->root->id % 5 == 4 || game->user->leftCardSet->root->id % 5 == 4) //user카드수5일때
    {
        for(int i=0;i<5;i++){ 
            if(game->npc->leftCardSet->root->id + i ==game->user->leftCardSet->root->id)
                return 1;
        }
        return 0;
    }
    else
    {
        return 0;
    }
}