#include "UI.h"

static void drawStrawberry(int posX, int posY)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	printOnPos("■■", posX + 2, posY);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	printOnPos("■■■", posX + 1, posY + 1);
	printOnPos("■■■■", posX, posY + 2);
	printOnPos("■■■", posX + 1, posY + 3);
	printOnPos("■■", posX + 2, posY + 4);
}

static void drawBanana(int posX, int posY)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	printOnPos("■■■", posX + 2, posY);
	printOnPos("■■", posX + 3, posY + 1);
	printOnPos("■■■", posX + 2, posY + 2);
	printOnPos("■■■", posX + 1, posY + 3);
}

static void drawPlum(int posX, int posY)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
	printOnPos("■", posX + 3, posY);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
	printOnPos("■■■", posX + 1, posY + 1);
	printOnPos("■■■■", posX, posY + 2);
	printOnPos("■■■", posX + 1, posY + 3);
	printOnPos("■■", posX + 2, posY + 4);
}

static void drawLime(int posX, int posY)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	printOnPos("■■", posX + 2, posY);
	printOnPos("■■■", posX + 1, posY + 1);
	printOnPos("■■■", posX, posY + 2);
	printOnPos("■■", posX + 1, posY + 3);
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