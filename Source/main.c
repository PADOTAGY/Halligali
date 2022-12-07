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
		if (game->key == SPACE && isActiveBombItem(game->user->item))
			game->key = NULL;
	}
}

int main()
{

	makeStartPage();
	Game *game = initGame();
	while (1)
	{
		readyGameboard(game);
		drawScreen(game);
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
		drawGameEndPage(game);
	}
	return 0;
}