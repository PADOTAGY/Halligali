#include "../Reusable.h"

int getRandomInt(int start, int end) {
    srand(time(NULL));
    
    return rand() % (end - start + 1) + start;
}