#include "NPC.h"

double getTimeWhenNPCDrawCard(void)
{
    int k;
    k = (int)(rand() % 30) * 1000; // 0~3초까지 사이의 실수
    return k;
}