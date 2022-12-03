#include "UI.h"

void deleteItem(int posX, int posY)
{
	for (int i = 0; i < ITEM_SIZE_HEIGHT; i++)
		printOnPos("                        ", posX + 1, posY + i + 1);
}

static void drawRuleChangeItem(int state, int posX, int posY)
{
	if (state == Active)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	}
	else
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
	}

	posX += 12;
	posY += 6;

	printOnPos(" _____", posX, posY - 1);
	printOnPos("|A .  |", posX, posY);
	printOnPos("| /.\\ |", posX, posY + 1);
	printOnPos("|(_._)|", posX, posY + 2);
	printOnPos("|  |  |", posX, posY + 3);
	printOnPos("|____V|", posX, posY + 4);
}

static void drawBombItem(int state, int posX, int posY)
{
	if (state == Active)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	}
	else
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
	}

	posX += 8;
	posY += 6;

	printOnPos("	  ,--.!,", posX, posY);
	printOnPos("     __/ -*-", posX, posY + 1);
	printOnPos("   ,d08b.\'|`", posX, posY + 2);
	printOnPos("   0088MM", posX, posY + 3);
	printOnPos("   `9MMP\'", posX, posY + 4);
}

static void drawStarItem(int state, int posX, int posY)
{
	if (state == Active)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	}
	else
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
	}

	posX += 7;
	posY += 4;

	printOnPos(".", posX + 8, posY);
	printOnPos(",O,", posX + 7, posY + 1);
	printOnPos(",OOO,", posX + 6, posY + 2);
	printOnPos("\'oooooOOOOOooooo'", posX, posY + 3);
	printOnPos("`OOOOOOOOOOO`", posX + 2, posY + 4);
	printOnPos("OOOO\'OOOO", posX + 4, posY + 5);
	printOnPos("OOO\'   \'OOO", posX + 3, posY + 6);
	printOnPos("O\'         \'O ", posX + 2, posY + 7);
}

static void drawWinItem(int state, int posX, int posY)
{
	if (state == Active)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	}
	else
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
	}

	posX += 9;
	posY += 5;

	printOnPos("  _______", posX, posY);
	printOnPos(" |       |", posX, posY + 1);
	printOnPos("(| SSAfS |)", posX, posY + 2);
	printOnPos(" |  #X   |", posX, posY + 3);
	printOnPos("  \\     /", posX, posY + 4);
	printOnPos("   `---'", posX, posY + 5);
	printOnPos("   _|_|_", posX, posY + 6);
}

void drawItem(Item *item, int posX, int posY)
{
	if (item == NULL)
		return;

	switch (item->id)
	{
	case RuleChangeItemId:
		drawRuleChangeItem(item->state, posX, posY);
		break;

	case BombItemId:
		drawBombItem(item->state, posX, posY);
		break;

	case StarItemId:
		drawStarItem(item->state, posX, posY);
		break;

	case WinItemId:
		drawWinItem(item->state, posX, posY);
		break;
	}
}
