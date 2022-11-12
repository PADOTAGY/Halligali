
#include "UI.h"


int main()
{
	initTerminal();

    drawScreen();

	drawHitBellMotion();

	for (int i = 0; i < 100; i++)
	{
		
		deleteCard(CARD_POS_X_NPC_L, CARD_POS_Y_NPC_L);
		drawCard(rand() % 20, CARD_POS_X_NPC_L, CARD_POS_Y_NPC_L);
		deleteCard(CARD_POS_X_NPC_R, CARD_POS_Y_NPC_R);
		drawCard(rand() % 20, CARD_POS_X_NPC_R, CARD_POS_Y_NPC_R);
		deleteCard(CARD_POS_X_PERSON_L, CARD_POS_Y_PERSON_L);
		drawCard(rand() % 20, CARD_POS_X_PERSON_L, CARD_POS_Y_PERSON_L);
		deleteCard(CARD_POS_X_PERSON_R, CARD_POS_Y_PERSON_R);
		drawCard(rand() % 20, CARD_POS_X_PERSON_R, CARD_POS_Y_PERSON_R);
		drawHitBellMotion();
		Sleep(2000);

	}

	getchar();
}