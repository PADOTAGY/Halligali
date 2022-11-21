#include "NPC.h"

//time함수를 이용하면 초(s)단위로 측정되는 한계가 있다.
//따라서 clock함수를 이용하여 ms 단위로 측정.

double returnTimeInput(void) {
    clock_t start, end;
    double result;
    int n;
    start = clock();  //시간 측정 시작

    scanf("%d", &n);    //실행할 코드

    end = clock(); //시간 측정 종료

   
    result = (double)(end)-(double)(start);
    result /= 1000; //ms을 s로 표현하게 하기 위해

    return result;
}



int main() {
    printf("%f",returnTimeInput());
}
