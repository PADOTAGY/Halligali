# include "UI.h"

static void RemoveCursor(void)
{
	CONSOLE_CURSOR_INFO curInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curInfo.bVisible = 0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
}

void initTerminal(void)
{
	SetConsoleOutputCP(CP_UTF8);
	system("mode con cols=240 lines=63");
	RemoveCursor();
}