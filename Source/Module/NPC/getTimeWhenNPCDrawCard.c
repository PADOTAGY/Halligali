#include<NPC.h>

double getTimeWhenNPCDrawCard(void) {
    float k;
    k = (float)(rand() % 30) / 10;  //0~3�ʱ��� ������ �Ǽ�
    return k;
}