#include "NPC.h"


void npcDrawCard(Game *game) {
   if (checkIsNPCAdvantage(game) == 1)  //npc의 카드 수가 5일 때
   {
      npcDifficultyControl(game);
   }

   else if (checkIsNPCAdvantage(game) == 0)  //npc의 카드 수가 5아닐 때
   {
      
      choosePositionWhenNPCDrawCardAndDrawCard(game);
   }
}