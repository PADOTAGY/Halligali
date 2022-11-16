
#include "UI.h"

void ProcessKeyInput() // get input
{
	for (int i = 0; i < 100; i++) // 20 input / 1 sec
	{
		if (_kbhit() != 0) // if there was keyboard hit
		{
			int key = _getch(); // get key
			switch (key)
			{
			case SPACE: drawHitBellMotionTest(1); Sleep(50); break;
			}
		}
		drawHitBellMotionTest(0);
		Sleep(10);
	}
}

int main()
{
	initTerminal();

    drawScreen();


	while (1)
	{
		ProcessKeyInput();
	}

}