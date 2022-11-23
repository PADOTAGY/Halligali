#include "NPC.h"

//time함수를 이용하면 초(s)단위로 측정되는 한계가 있다.
//따라서 clock함수를 이용하여 ms 단위로 측정.


//user가 space바를 입력했는지 확인하는 함수. space바 입력 시 함수 종료


double getTimeUserPutDownBell(Game *game) 
{
   clock_t start, end;
   double result;
   //종을 치는 조건이 충족되면
   start = clock();  //시간 측정 시작
   int cntt=0;
   //userKeyInputPutDownBell();

   switch(game->key){
      case SPACE:
         game->npc->cntUserPutDownBell++;
         cntt++;
         break;
      if(cntt==1) break;
   }
   
    end = clock(); //시간 측정 종료


    result = (double)(end)-(double)(start);
    //result /= 1000; //ms을 s로 표현하게 하기 위해
   //해성님 UI로 출력할 때 return받은 값 1000으로 나눠서 출력해주세요..!
    return result;
}
