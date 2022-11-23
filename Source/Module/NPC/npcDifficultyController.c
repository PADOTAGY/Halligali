#include "NPC.h"

//npc의 드로우된 카드 중 5가 있다면.
void npcDifficultyControl()
{
   if (game.npc.leftCardSet.root.id % 5 == 4) //npc왼쪽 카드더미에서 5가 나온다면
   {
      //drawCard가 두현님 코드라면 (로직)
      //drawCard(npc, RIGHT);;

      //drawCard가 해성님 코드라면  (UI)
      //drawCard(카드번호, CARD_POS_X_NPC_R,CARD_POS_Y_NPC_R);
   }
   else if(game.npc.rightCardSet.root.id % 5 == 4) //npc오른쪽 카드더미에서 5가 나온다면
   {
      //drawCard가 두현님 코드라면
      //drawCard(npc, LEFT);;

      //drawCard가 해성님 코드라면
      //drawCard(카드번호, CARD_POS_X_NPC_L,CARD_POS_Y_NPC_L);
   }
}