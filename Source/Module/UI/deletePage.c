
#define SCREEN_MID_X 120
#define SCREEN_MID_Y 32

#include "UI.h"

void deletePage()
{
    for (int line = 0; line < 63; line++)
        printOnPos("                                                                                                                                                                                                                                                ", 0, line);
}