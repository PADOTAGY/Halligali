#include "NPC.h"

void npcPutDownBell(Game *game, NPC *npc)
{

    game->whoBell = 1;

    int countAll = game->user->leftCardSet->count + game->user->rightCardSet->count + game->npc->leftCardSet->count + game->npc->rightCardSet->count;
    if (game->npc->originCardSet->count == 0)
    {
        game->npc->originCardSet->root = mergedCardSet(game);
    }
    else
    {
        struct Card *p = getCard(game->npc->originCardSet, game->npc->originCardSet->count - 1);
        p->next = mergedCardSet(game);
    }
    game->npc->originCardSet->count += countAll;

    npc->tmpAvgTimeUserPutDownBell *= 1.1; // npc종 쳤을 때 난이도 하락
}

int isNiceBellNPC(Game *game)
{
    int sum[6] = {0};

    if (game->user->leftCardSet->count > 0)
        sum[game->user->leftCardSet->root->id / 5] += game->user->leftCardSet->root->id % 5 + 1;
    if (game->user->rightCardSet->count > 0)
        sum[game->user->rightCardSet->root->id / 5] += game->user->rightCardSet->root->id % 5 + 1;
    if (game->npc->leftCardSet->count > 0)
        sum[game->npc->leftCardSet->root->id / 5] += game->npc->leftCardSet->root->id % 5 + 1;
    if (game->npc->rightCardSet->count > 0)
        sum[game->npc->rightCardSet->root->id / 5] += game->npc->rightCardSet->root->id % 5 + 1;

    //npc 종치기
    
    // if(isActiveRuleChangeItem(game->user->item))
    // {
    //     for (int i = 0; i < 4; i++)
    //         if (((sum[4] + sum[i]) % 5 == 0 || (sum[4] + sum[i]) % 3 == 0) && sum[4] + sum[i] != 0)
    //             return 1;
    //     return 0; 
    // }
    //else{
        for (int i = 0; i < 4; i++)
            if ((sum[4] + sum[i]) % 5 == 0 && sum[4]+sum[i] != 0)
                return 1;
        return 0;
   // }
   
    
    
}