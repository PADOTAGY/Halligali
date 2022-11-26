#include "NPC.h"

void npcPutDownBell(Game *game,NPC *npc){
    //Sleep(npc->tmpAvgTimeUserPutDownBell); //user평균 시간 지난 후
    //sleep함수 쓰지말고 시간지연하는 방법 찾기..

    game->whoBell=1;

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

    game->whoBell=-1;
        
}