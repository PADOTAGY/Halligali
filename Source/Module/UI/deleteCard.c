#include "UI.h"

void deleteCard(int posX, int posY)
{
	for (int i = 0; i < 15; i++)
	{
		setCurrentCursorPos(posX, posY+i);
		printf("                    ");
	}
}