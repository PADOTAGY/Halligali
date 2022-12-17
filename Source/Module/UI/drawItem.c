#include "UI.h"

void deleteItem(int posX, int posY)
{
	for (int i = 0; i < ITEM_SIZE_HEIGHT; i++)
		printOnPos("                       ", posX + 2, posY + i + 1);
}

static void drawRuleChangeItem(int state, int posX, int posY)
{
	if (state == Active)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		PlaySound(TEXT(RULL_CHANGE_SOUND), NULL, SND_ASYNC);
	}
	else
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
		PlaySound(TEXT(ITEM_GET_SOUND), NULL, SND_SYNC);
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

	PlaySound(TEXT(BOMB_SOUND), NULL, SND_SYNC);
}

static void drawStarItem(int state, int posX, int posY)
{
	if (state == Active)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		PlaySound(TEXT(STAR_SOUND), NULL, SND_ASYNC);
	}
	else
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
		PlaySound(TEXT(ITEM_GET_SOUND), NULL, SND_SYNC);
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
		PlaySound(TEXT(FANFARE_SOUND), NULL, SND_ASYNC);
	}
	else
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
		PlaySound(TEXT(ITEM_GET_SOUND), NULL, SND_SYNC);
	}

	posX += 9;
	posY += 5;

	printOnPos("  _______", posX, posY);
	printOnPos(" |       |", posX, posY + 1);
	printOnPos("(| W I N |)", posX, posY + 2);
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
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
		printOnPos("3의 배수도", 239 - 30 + 2, posY + 2);
		printOnPos("승리 조건입니다.", 239 - 30 + 2, posY + 4);
		printOnPos("tip: NPC는 ", 239 - 30 + 2, posY + 8);
		printOnPos("     그 사실을 몰라요 !", 239 - 30 + 2, posY + 10);

		break;

	case BombItemId:
		drawBombItem(item->state, posX, posY);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
		printOnPos("3턴 동안 ", 239 - 30 + 2, posY + 2);
		printOnPos("종을 누르지 못하게 됩니다.", 239 - 30 + 2, posY + 4);
		printOnPos("tip: 조금만", 239 - 30 + 2, posY + 8);
		printOnPos("     기다리세요 !", 239 - 30 + 2, posY + 10);

		break;

	case StarItemId:
		drawStarItem(item->state, posX, posY);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
		printOnPos("5턴 동안", 239 - 30 + 2, posY + 2);
		printOnPos("패널티가 없습니다.", 239 - 30 + 2, posY + 4);
		printOnPos("tip: 종을", 239 - 30 + 2, posY + 8);
		printOnPos("     마구누르세요 !", 239 - 30 + 2, posY + 10);

		break;

	case WinItemId:
		drawWinItem(item->state, posX, posY);
		printOnPos("사용 후 종을 누르면 ", 239 - 30 + 2, posY + 2);
		printOnPos("승리합니다..", 239 - 30 + 2, posY + 4);
		printOnPos("tip: 카드가 많이 ", 239 - 30 + 2, posY + 8);
		printOnPos("     쌓인 판에서 사용하세요 !", 239 - 30 + 2, posY + 10);
		break;
	}
}
