#include<NPC.h>

double getTimeWhenNPCDrawCard(void) {
    float k;
    k = (float)(rand() % 30) / 10;  //0~3초까지 사이의 실수
    return k;
}