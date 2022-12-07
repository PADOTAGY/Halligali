#ifndef UI_H
#define UI_H

#define SCREEN_MID_X 120
#define SCREEN_MID_Y 32

#define BELL_BASIS_X 110
#define BELL_BASIS_Y 25
#define HAND_BASIS_X 95

#define CARD_POS_X_NPC_L 70
#define CARD_POS_Y_NPC_L 8
#define CARD_POS_X_NPC_R 150
#define CARD_POS_Y_NPC_R 8
#define CARD_POS_X_PERSON_L 70
#define CARD_POS_Y_PERSON_L 39
#define CARD_POS_X_PERSON_R 150
#define CARD_POS_Y_PERSON_R 39

#define ITEM_SIZE_WIDTH 28
#define ITEM_SIZE_HEIGHT 14
#define ITEM_POS_X 180
#define ITEM_POS_Y 47

#include "../Reusable/Reusable.h"
#include "../Item/item.h"

typedef struct _CoordStr
{
    int posX;
    char str[130];
    char blank[130];
} CoordStr;

void deletePage();
void updateUI(Game *game);
void drawBell();
void reDrawBell();

// UIUtil
void setCurrentCursorPos(int x, int y);
COORD getCurrentCursorPos(void);
void printOnPos(const char *str, int posX, int posY);

// drawHitBellMotion
void drawBell();
void drawHitBellMotion();
void drawHitBellMotionNPC(int flint);

void initTerminal(void);
void drawScreen(Game *game);
void drawCard(int cardID, int posX, int posY);
void deleteCard(int posX, int posY);

void drawHitBellMotionTest(int flint);

void drawGameStartPage();
void drawGameEndPage(Game *game);

void updateScore(Game *game);
void updateCardSetNumber(Game *game);

void drawItem(Item *item, int posX, int posY);
void deleteItem(int posX, int posY);

#endif