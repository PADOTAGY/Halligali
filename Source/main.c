#include "Module/Game/game.h"
#include "Module/Card/card.h"
#include "Module/Item/item.h"
#include "Module/NPC/NPC.h"
#include "Module/UI/UI.h"
#include "Module/User/user.h"
#include "Module/Reusable/Reusable.h"

void getKey(Game *game)
{
	if (_kbhit() != 0)
	{
		game->key = _getch();
	}
}

int main()
{
	makeStartPage();

	Game *game = initGame();
	while (1)
	{
		readyGameboard(game);
		while (1)
		{
			getKey(game);
			cardHandler(game);
			runItemModule(game);
			runNPCModule(game);
			updateUI(game);
			if (checkAndRunEndGame(game))
				break;
			game->key = 0;
			game->playTime += game->sleepMs;
			Sleep(game->sleepMs);
		}
		Sleep(1000); //게임이 끝나고 endPage를 띄우기 위함.
		drawGameEndPage();
	}
	return 0;
}