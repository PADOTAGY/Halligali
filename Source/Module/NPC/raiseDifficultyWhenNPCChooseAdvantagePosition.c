#include "NPC.h"

double AvgTimeUserPutDownBell = 0.0;
double tmpAvgTimeUserPutDownBell;

tmpAvgTimeUserPutDownBell = AvgTimeUserPutDownBell;
AvgTimeUserPutDownBell *= 0.3; //난이도 상승

//나중에 메인로직에서 AvgTimeUserPutDownBell값에 tmpAvgTimeUserPutDownBell값 넣기