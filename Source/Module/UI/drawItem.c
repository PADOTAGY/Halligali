#include "UI.h"

void deleteItem(int posX, int posY) {
	for (int i = 0; i < 10; i++)
		printOnPos("          ", posX, posY + i);
}

static void drawRuleChangeItem(int state, int posX, int posY) {
    if (state == Active) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
    } else {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    }
}

static void drawBombItem(int state, int posX, int posY) {
    if (state == Active) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
    } else {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    }
}

static void drawStarItem(int state, int posX, int posY) {
    if (state == Active) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
    } else {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    }
    printOnPos(".", posX + 8, posY);
    printOnPos(",O,", posX + 7, posY + 1);
    printOnPos(",OOO,", posX + 6, posY + 2);
    printOnPos("\'oooooOOOOOooooo'", posX, posY + 3);
    printOnPos("`OOOOOOOOOOO`", posX + 2, posY + 4);
    printOnPos("OOOO\'OOOO", posX + 4, posY + 5);
    printOnPos("OOO\'   \'OOO", posX + 3, posY + 6);
    printOnPos("O\'         \'O ", posX + 2, posY + 7);
}

static void drawWinItem(int state, int posX, int posY) {
    if (state == Active) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
    } else {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    }
}

static void drawItem(Item item, int posX, int posY) {
    if (item == NULL) return;

}

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
	int number = cardID % 5 + 1;
	void (*drawFruit)() = 0;
	deleteCard(posX, posY);
	if (fruit == 0)
		drawFruit = drawStrawberry;
	else if (fruit == 1)
		drawFruit = drawBanana;
	else if (fruit == 2)
		drawFruit = drawPlum;
	else if (fruit == 3)
		drawFruit = drawLime;
	else
		return;

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

// "              ██"
// "            ██  ██"
// "            ██  ██"
// "          ██      ██"
// "          ██      ██"
// "██████████          ██████████"
// "██          ██  ██          ██"
// "  ██        ██  ██        ██"
// "    ██      ██  ██      ██"
// "      ██              ██"
// "    ██                  ██"
// "    ██                  ██"
// "  ██          ██          ██"
// "  ██      ████  ████      ██"
// "██    ████          ████    ██"
// "██████                  ██████"

//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//        .
//        ,O,
//       ,OOO,
// 'oooooOOOOOooooo'
//   `OOOOOOOOOOO`
//     `OOOOOOO`
//     OOOO'OOOO
//    OOO'   'OOO
//   O'         'O
//
//
//
//
//
//

//
//           ███
//         ██░░░██
//       ███░░░░░░███
//   ████░░░░░░░░░░░░████
//  █░░░░░░░░░░░░░░░░░░░░█
//  █▓░░░░░░ █░░ █░░░░░░▓█
//   █▓░░░░░██░░██░░░░░▓█
//     █▓░░░░░░░░░░░░▓█
//      █▓░░▓███▓░░▓█
//        ▓█     █▓
//
//                         ██████
//                     ████░░░░░░██
//                   ██░░░░░░░░██
//                 ██░░░░░░░░░░░░██
//               ██░░░░░░░░░░░░░░░░██
//             ██░░░░░░░░░░░░░░░░░░██
//             ██░░░░░░░░░░░░░░░░░░░░██
//     ████████░░░░░░░░░░░░░░░░░░░░░░░░████████
//   ██░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██
//   ██▓▓░░░░░░░░░░░░  ██░░░░  ██░░░░░░░░░░░░▓▓██
//     ██▓▓░░░░░░░░░░████░░░░████░░░░░░░░░░▓▓██
//       ██▓▓░░░░░░░░████░░░░████░░░░░░░░▓▓██
//         ██░░░░░░░░▓▓██░░░░██▓▓░░░░░░░░██
//         ██░░░░░░░░░░░░░░░░░░░░░░░░░░░░██
//         ██░░░░░░░░░░░░░░░░░░░░░░░░░░░░██
//         ██▓▓░░░░░░░░░░░░░░░░░░░░░░░░▓▓██
//         ██▓▓░░░░░░░░░░░░░░░░░░░░░░░░▓▓██
//           ██░░░░▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓░░░░██
//           ██▓▓░░▓▓████████████▓▓░░▓▓██
//             ██▓▓██            ██▓▓██
//               ██                ██

// 개기엽누 작게 만들자