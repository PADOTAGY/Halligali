#include "game.h"

void makeStartPage()
{
	initTerminal();
	drawGameStartPage();
	getchar();
	deletePage();
}