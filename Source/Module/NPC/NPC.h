#ifndef NPC_H
#define NPC_H

#define SPACE 32
#define LEFT 75
#define RIGHT 77
#define CARD_POS_X_NPC_L 70
#define CARD_POS_Y_NPC_L 8
#define CARD_POS_X_NPC_R 150
#define CARD_POS_Y_NPC_R 8

#include "../Reusable/Reusable.h"

//함수 선언
double getTimeWhenNPCDrawCard(void);
void calcAverageTimeUserPutDownBell(Game *game, NPC *npc);
double getTimeUserPutDownBell(Game *game);
int checkIsNPCAdvantage(Game *game);
void npcDrawCard(Game *game);
void choosePositionWhenNPCDrawCardAndDrawCard(Game *game);
void npcDifficultyControl(Game *game);
void raiseDifficultyNPCAdvantage(Game *game);
void returnRaiseDifficultyNPCAdvantage(Game *game);

void updateIsMissPutDownBell(Game *game, NPC *npc);
#endif