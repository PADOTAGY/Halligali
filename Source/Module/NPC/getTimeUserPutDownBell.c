#include "NPC.h"

//time함수를 이용하면 초(s)단위로 측정되는 한계가 있다.
//따라서 clock함수를 이용하여 ms 단위로 측정.


//user가 space바를 입력했는지 확인하는 함수. space바 입력 시 함수 종료
void userKeyInputPutDownBell(void)  
{
   int key;
   int cntt;

   while (!_kbhit())
   {
      cntt = 0;
      key = _getch();
      switch (key) {
      case SPACE:
         cntUserPutDownBell++;
         cntt++;
         break;
      }
      if (cntt == 1)break;
   }
}

double getTimeUserPutDownBell(void) 
{
    clock_t start, end;
    double result;
 
    start = clock();  //시간 측정 시작

   userKeyInputPutDownBell();
   
    end = clock(); //시간 측정 종료


    result = (double)(end)-(double)(start);
    result /= 1000; //ms을 s로 표현하게 하기 위해

    return result;
}
