#include "NPC.h"

//time�Լ��� �̿��ϸ� ��(s)������ �����Ǵ� �Ѱ谡 �ִ�.
//���� clock�Լ��� �̿��Ͽ� ms ������ ����.

double returnTimeInput(void) {
    clock_t start, end;
    double result;
    int n;
    start = clock();  //�ð� ���� ����

    scanf("%d", &n);    //������ �ڵ�

    end = clock(); //�ð� ���� ����

   
    result = (double)(end)-(double)(start);
    result /= 1000; //ms�� s�� ǥ���ϰ� �ϱ� ����

    return result;
}



int main() {
    printf("%f",returnTimeInput());
}
