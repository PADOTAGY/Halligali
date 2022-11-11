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

static void drawBell()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
	setCurrentCursorPos(SCREEN_MID_X - 21 + 11, SCREEN_MID_Y - 7);
    printf(".,.,./&&&&&&&&''...");
	setCurrentCursorPos(SCREEN_MID_X - 21 + 6, SCREEN_MID_Y-6);
    printf(".,, ,,...&&&&&&&&&&&&,.....,");
	setCurrentCursorPos(SCREEN_MID_X - 21 + 4, SCREEN_MID_Y-5);
    printf(",,,.., . *&&&&&&&&&&&&&&.,...,.,.");
	setCurrentCursorPos(SCREEN_MID_X- 21 + 3, SCREEN_MID_Y-4);
    printf(",.,.,,, .   &&&&&&&&&&&&    ..,,.,,");
	setCurrentCursorPos(SCREEN_MID_X- 21 + 2, SCREEN_MID_Y-3);
    printf(",  ....,,     '&&&&&&&&/       .....,");
	setCurrentCursorPos(SCREEN_MID_X- 21 + 2, SCREEN_MID_Y-2);
    printf(".                                ..,,");
	setCurrentCursorPos(SCREEN_MID_X- 21 + 1, SCREEN_MID_Y-1);
    printf(",.             .         .    .....,,..");
	setCurrentCursorPos(SCREEN_MID_X-21, SCREEN_MID_Y);
    printf(" #,              ............,,.,,.....#.");
	setCurrentCursorPos(SCREEN_MID_X-21, SCREEN_MID_Y+1);
    printf(".##..        ..............,,,,.......(#*");
	setCurrentCursorPos(SCREEN_MID_X- 21 + 1, SCREEN_MID_Y+2);
    printf("##&/,..        ..................,,,&&#/");
	setCurrentCursorPos(SCREEN_MID_X- 21 + 1, SCREEN_MID_Y+3);
    printf("(#&&(&(**,,..            ...,,**,&#&&&&");
	setCurrentCursorPos(SCREEN_MID_X- 21 + 2, SCREEN_MID_Y+4);
    printf(".&&&&&##&&&(//************/#&#&&&&&&&");
	setCurrentCursorPos(SCREEN_MID_X- 21 + 5, SCREEN_MID_Y+5);
    printf("&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&/");
	setCurrentCursorPos(SCREEN_MID_X- 21 + 8, SCREEN_MID_Y+6);
    printf("*&&&&&&&&&&&&&&&&&&&&&&&&/");
	setCurrentCursorPos(SCREEN_MID_X- 21 + 12, SCREEN_MID_Y+7);
    printf("'&&&&&&&&&&&&&&&&&/");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

void drawScreen(void)
{
	drawPlaceForCard(CARD_POS_X_NPC_L, CARD_POS_Y_NPC_L);
	drawPlaceForCard(CARD_POS_X_NPC_R, CARD_POS_Y_NPC_R);
	drawPlaceForCard(CARD_POS_X_PERSON_L, CARD_POS_Y_PERSON_L);
	drawPlaceForCard(CARD_POS_X_PERSON_R, CARD_POS_Y_PERSON_R);
	drawBell();
}
