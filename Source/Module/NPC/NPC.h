#ifndef NPC_H
#define NPC_H
#include "../Reusable/Reusable.h"

//함수 선언
// npc 카드 내려 놓기
int checkIsNPCAdvantage(Game *game);
void npcPutDownCard(Game *game);
void npcPutDownCardNotAdvantage(Game *game);
void npcPutDownRightCardAdvantage(game);
void npcPutDownLeftCardAdvantage(Game *game);
double getTimeWhenNPCDrawCard(void);
// npc 난이도 조절
void raiseDifficultyNPCAdvantage(NPC *npc);
void returnRaiseDifficultyNPCAdvantage(NPC *npc);
// user가 종치는 시간관련
void calcAverageTimeUserPutDownBell(Game *game, NPC *npc);
double getTimeUserPutDownBell(Game *game);
// npc 종치기
void npcPutDownBell(Game *game, NPC *npc);
void missPutDownBell(Game *game, NPC *npc);
int isMissPutDownBell(Game *game, NPC *npc);

#endif