#ifndef NPC_H
#define NPC_H

#define SPACE 32
#define LEFT 75
#define RIGHT 77
#define CARD_POS_X_NPC_L 70
#define CARD_POS_Y_NPC_L 8
#define CARD_POS_X_NPC_R 150
#define CARD_POS_Y_NPC_R 8

# include <stdio.h>
# include <Windows.h>
# include <time.h>
# include <conio.h>
# include "../module.h"

//함수 선언
double getTimeWhenNPCDrawCard(void);
double getTimeUserPutDownBell(void);
void userKeyInputPutDownBell(void);
void calcAverageTimeUserPutDownBell(void);
int checkIsNPCAdvantage(void);
void npcDrawCard();
void choosePositionWhenNPCDrawCardAndDrawCard();
void npcDifficultyControl(Game *game);



//구조체 
// typedef struct Game {
// 	GameState state;
// 	NPC *npc;
// 	User *user;
// 	int mode;
// 	int key;
// 	int gameCnt;
// 	int drawCnt;
// 	double playTime;
// } Game;

struct CardSet
{
    struct Card *root;
    int count;
};
struct Card
{
    CardId id;
    struct Card *next; // struct Card *prev 삭제
};

typedef struct NPC {
    struct CardSet *originCardSet;
    struct CardSet *leftCardSet;
    struct CardSet *rightCardSet;
    int score;

    double AvgTimeUserPutDownBell;
    double totalTimeUserPutDownBell = 0.0; 
    double AvgTimeUserPutDownBell = 0.0;
    double tmpAvgTimeUserPutDownBell;
    int cntUserPutDownBell = 0;  //getTimeUserPutDownBell 실행 시마다 +1
}NPC;


#endif