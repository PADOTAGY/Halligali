#include "NPC.h"

// npc의 드로우된 카드 중 5가 있다면.
void npcDifficultyControl(Game *game)
{
     raiseDifficultyNPCAdvantage(game);
     Sleep(getTimeWhenNPCDrawCard() * 1000);
     if (game->npc->leftCardSet->root->id % 5 == 4) // npc왼쪽 카드더미에서 5가 나온다면
     {
          putDownCard(game->npc->originCardSet, game->npc->rightCardSet);
     }

     else if (game->npc->rightCardSet->root->id % 5 == 4) // npc오른쪽 카드더미에서 5가 나온다면
     {
          putDownCard(game->npc->originCardSet, game->npc->leftCardSet);
          // drawCard(npc->leftCardSet->root->id,CARD_POS_X_NPC_L,CARD_POS_Y_NPC_L)
     }

     returnRaiseDifficultyNPCAdvantage(game);
}