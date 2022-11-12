#include "UI.h"

static void drawPlaceForCard(int posX, int posY)
{
	printOnPos("┌─────────────────────┐", posX - 2, posY - 1);
	
	for (int i = 0; i < 15; i++)
		printOnPos("│                     │", posX - 2, posY + i);

	printOnPos("└─────────────────────┘", posX - 2, posY + 15);
}

void drawScreen(void)
{
	drawPlaceForCard(CARD_POS_X_NPC_L, CARD_POS_Y_NPC_L);
	drawPlaceForCard(CARD_POS_X_NPC_R, CARD_POS_Y_NPC_R);
	drawPlaceForCard(CARD_POS_X_PERSON_L, CARD_POS_Y_PERSON_L);
	drawPlaceForCard(CARD_POS_X_PERSON_R, CARD_POS_Y_PERSON_R);
	drawBell();
}
