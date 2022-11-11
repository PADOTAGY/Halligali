#ifndef UI_H
# define UI_H

# include <stdio.h>
# include <Windows.h>

#define SCREEN_MID_X 120
#define SCREEN_MID_Y 32

#define CARD_POS_X_NPC_L 70
#define CARD_POS_Y_NPC_L 8
#define CARD_POS_X_NPC_R 150
#define CARD_POS_Y_NPC_R 8
#define CARD_POS_X_PERSON_L 70
#define CARD_POS_Y_PERSON_L 39
#define CARD_POS_X_PERSON_R 150
#define CARD_POS_Y_PERSON_R 39

// UIUtil
void setCurrentCursorPos(int x, int y);
COORD getCurrentCursorPos(void);

void initTerminal(void);
void drawScreen(void);
void drawCard(int cardID, int posX, int posY);
void deleteCard(int posX, int posY);

#endif