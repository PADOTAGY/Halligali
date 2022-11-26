#include "NPC.h"

double getTimeWhenNPCDrawCard(void)
{
    double k;
    k = (double)(rand() % 30) / 10 * 1000; // 0~3초까지 사이의 실수
    return k;
}