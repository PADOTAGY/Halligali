#include "UI.h"

static void drawPlaceForCard(int posX, int posY)
{
	setCurrentCursorPos(posX - 2, posY - 1);
	printf("┌─────────────────────┐");
	for (int i = 0; i < 15; i++)
	{
		setCurrentCursorPos(posX - 2, posY + i);
		printf("│                     │");
	}
	setCurrentCursorPos(posX - 2, posY + 15);
	printf("└─────────────────────┘");
}

void drawScreen(void)
{
	drawPlaceForCard(CARD_POS_X_NPC_L, CARD_POS_Y_NPC_L);
	drawPlaceForCard(CARD_POS_X_NPC_R, CARD_POS_Y_NPC_R);
	drawPlaceForCard(CARD_POS_X_PERSON_L, CARD_POS_Y_PERSON_L);
	drawPlaceForCard(CARD_POS_X_PERSON_R, CARD_POS_Y_PERSON_R);
	drawBell();
}
