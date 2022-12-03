#include "NPC.h"

int getTimeWhenNPCDrawCard(void)
{
   int k;
   k = (int)((rand() % 30) * 100); // 0~3초까지 사이의 실수
   return k;
}