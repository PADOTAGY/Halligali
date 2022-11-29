#include "UI.h"

static void drawTable()
{
	for (int i = 0; i < 63; i++)
	{
		printOnPos("│", 30, i);
		printOnPos("│", 239 - 30, i);
	}
}

static void drawPlaceForCard(int posX, int posY)
{
	printOnPos("┌─────────────────────┐", posX - 2, posY - 1);
	
	for (int i = 0; i < 15; i++)
		printOnPos("│                     │", posX - 2, posY + i);

	printOnPos("└─────────────────────┘", posX - 2, posY + 15);
}

static void drawPlaceForCardSetCnt()
{
	// 11 방향
	printOnPos("┬───┤", CARD_POS_X_NPC_L - 2 + 18, CARD_POS_Y_NPC_L + 15);
	printOnPos("│   │", CARD_POS_X_NPC_L - 2 + 18, CARD_POS_Y_NPC_L + 16);
	printOnPos("└───┘", CARD_POS_X_NPC_L - 2 + 18, CARD_POS_Y_NPC_L + 17);

	// 7시 방향
	printOnPos("┌───┐", CARD_POS_X_PERSON_L - 2 + 18, CARD_POS_Y_PERSON_L - 3);
	printOnPos("│   │", CARD_POS_X_PERSON_L - 2 + 18, CARD_POS_Y_PERSON_L - 2);
	printOnPos("┴───┤", CARD_POS_X_PERSON_L - 2 + 18, CARD_POS_Y_PERSON_L - 1);

	// 4시 방향
	printOnPos("┌───┐", CARD_POS_X_PERSON_R - 2 , CARD_POS_Y_PERSON_R - 3);
	printOnPos("│   │", CARD_POS_X_PERSON_R - 2 , CARD_POS_Y_PERSON_R - 2);
	printOnPos("├───┴", CARD_POS_X_PERSON_R - 2 , CARD_POS_Y_PERSON_R - 1);

	// 1시 방향
	printOnPos("├───┬", CARD_POS_X_NPC_R - 2 , CARD_POS_Y_NPC_R + 15);
	printOnPos("│   │", CARD_POS_X_NPC_R - 2 , CARD_POS_Y_NPC_R + 16);
	printOnPos("└───┘", CARD_POS_X_NPC_R - 2 , CARD_POS_Y_NPC_R + 17);

}

void drawScreen(void)
{
	drawTable();
	drawPlaceForCard(CARD_POS_X_NPC_L, CARD_POS_Y_NPC_L);
	drawPlaceForCard(CARD_POS_X_NPC_R, CARD_POS_Y_NPC_R);
	drawPlaceForCard(CARD_POS_X_PERSON_L, CARD_POS_Y_PERSON_L);
	drawPlaceForCard(CARD_POS_X_PERSON_R, CARD_POS_Y_PERSON_R);
	drawPlaceForCardSetCnt();
	drawBell();
}
