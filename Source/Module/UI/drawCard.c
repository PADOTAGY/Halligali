#include "UI.h"

static void drawStrawberry(int posX, int posY)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	setCurrentCursorPos(posX + 2, posY);
	printf("■■");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	setCurrentCursorPos(posX + 1, posY + 1);
	printf("■■■");
	setCurrentCursorPos(posX, posY + 2);
	printf("■■■■");
	setCurrentCursorPos(posX + 1, posY + 3);
	printf("■■■");
	setCurrentCursorPos(posX + 2, posY + 4);
	printf("■■");
}

static void drawBanana(int posX, int posY)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	setCurrentCursorPos(posX + 2, posY);
	printf("■■■");
	setCurrentCursorPos(posX + 3, posY + 1);
	printf("■■");
	setCurrentCursorPos(posX + 2, posY + 2);
	printf("■■■");
	setCurrentCursorPos(posX + 1, posY + 3);
	printf("■■■");
}

static void drawPlum(int posX, int posY)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
	setCurrentCursorPos(posX + 3, posY);
	printf("■");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
	setCurrentCursorPos(posX + 1, posY + 1);
	printf("■■■");
	setCurrentCursorPos(posX, posY + 2);
	printf("■■■■");
	setCurrentCursorPos(posX + 1, posY + 3);
	printf("■■■");
	setCurrentCursorPos(posX + 2, posY + 4);
	printf("■■");
}

static void drawLime(int posX, int posY)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	setCurrentCursorPos(posX + 2, posY + 0);
	printf("■■");
	setCurrentCursorPos(posX + 1, posY + 1);
	printf("■■■");
	setCurrentCursorPos(posX, posY + 2);
	printf("■■■");
	setCurrentCursorPos(posX + 1, posY + 3);
	printf("■■");
}

void drawCard(int cardID, int posX, int posY)
{
	int fruit = cardID / 5;
	int number = cardID % 5 + 1 ;
	void (*drawFruit)() = 0;

	if (fruit == 0)
		drawFruit = drawStrawberry;
	else if (fruit == 1)
		drawFruit = drawBanana;
	else if (fruit == 2)
		drawFruit = drawPlum;
	else if (fruit == 3)
		drawFruit = drawLime;
	else return;

	switch (number)
	{
	case 5:
		drawFruit(posX, posY);
		drawFruit(posX + 12, posY + 10);
	case 3:
		drawFruit(posX, posY + 10);
		drawFruit(posX + 12, posY);
	case 1:
		drawFruit(posX + 6, posY + 5);
		break;
	case 4:
		drawFruit(posX, posY + 10);
		drawFruit(posX + 12, posY);
	case 2:
		drawFruit(posX, posY);
		drawFruit(posX + 12, posY + 10);
		break;
	}
}