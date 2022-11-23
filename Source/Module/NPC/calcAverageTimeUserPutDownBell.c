#include "NPC.h"

//double totalTimeUserPutDownBell = 0.0;
//double AvgTimeUserPutDownBell = 0.0;
//int cntUserPutDownBell = 0;  //putDownBell하면 +1

void calcAverageTimeUserPutDownBell(void) 
{
    double timeUserPutDownBell = getTimeUserPutDownBell();
    totalTimeUserPutDownBell += timeUserPutDownBell;
    AvgTimeUserPutDownBell = totalTimeUserPutDownBell / cntUserPutDownBell;

}
