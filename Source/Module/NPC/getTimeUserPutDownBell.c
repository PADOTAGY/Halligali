#include "NPC.h"

// time함수를 이용하면 초(s)단위로 측정되는 한계가 있다.
//따라서 clock함수를 이용하여 ms 단위로 측정.

double getTimeUserPutDownBell(Game *game)
{
   // clock_t start, end;
   // double result;
   // //종을 치는 조건이 충족되면

   //  if (isNiceBell(game)) //user가 올바르게 종을 칠 때만 실행
   // {
   //    start = clock();  //시간 측정 시작
   //    int cntt=0;

   //    switch(game->key){
   //       case SPACE:
   //          game->npc->cntUserPutDownBell++;
   //          cntt++;
   //          break;
   //       if(cntt==1) break;
   //    }

   //    end = clock(); //시간 측정 종료
   // }

   //  result = (double)(end)-(double)(start);
   //  return result;
   game->npc->cntUserPutDownBell++;

   if (game->playTime - game->lastTime < 200)
      return game->npc->tmpAvgTimeUserPutDownBell;
   else if (game->playTime - game->lastTime > 3500)
      return game->npc->tmpAvgTimeUserPutDownBell;
   else
      return game->playTime - game->lastTime;
}
