#include "game.h"

void makeEndPage()
{
    deletePage();
	drawGameEndPage();
	getchar();
	deletePage();
}