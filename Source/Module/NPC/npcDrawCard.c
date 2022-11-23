#include "NPC.h"

/*
checkIsNPCAdvantage
npcDifficultyController
npcRaiseDifficulty
chooseAdvantagePositionWhenNPCPutDownBell 
에 있는 함수가 포함될 예정입니다.
*/

void npcDrawCard() {
   if (checkIsNPCAdvantage == 1)  //user의 카드 수가 5일 때
   {
      npcDifficultyControl();
   }
   else if (checkIsNPCAdvantage == 0)  //user의 카드 수가 5아닐 때
   {
      //drawCard가 두현님 코드라면 (로직)
      //drawCard(npc, RIGHT);;

      //drawCard가 해성님 코드라면  (UI)
      //drawCard(카드번호, CARD_POS_X_NPC_R,CARD_POS_Y_NPC_R);
      choosePositionWhenNPCDrawCardAndDrawCard();
   }
}