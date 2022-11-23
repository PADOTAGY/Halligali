#include "NPC.h"

void choosePositionWhenNPCDrawCardAndDrawCard(Game *game)
{
    int ran;
    ran = rand() % 2;

    Sleep(getTimeWhenNPCDrawCard()*1000);

    if (ran == 0) //NPC오른쪽에 카드 놓기
    {
        putDownCard(game->npc->originCardSet, game->npc->rightCardSet);
    }
    else if (ran==1)  //NPC왼쪽에 카드 놓기
    {
        putDownCard(game->npc->originCardSet, game->npc->leftCardSet);
        //drawCard(game->npc->leftCardSet->root->id,CARD_POS_X_NPC_L,CARD_POS_Y_NPC_L);
    }
}