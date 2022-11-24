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
	Game *game = initGame();
	readyGameboard(game);
	while (1)
	{
		while (1)
		{
			getKey(game);
			cardHandler(game);
			runItemModule(game, 10); // 아이템
			// 카드 내려놓기
			// 벨 누르기
			// npc
			// 승리조건
			updateUI(game); // UI
			game->key = 0;

			if (checkAndRunEndGame(game))
			{
				readyGameboard(game);
				break;
			}
			Sleep(20);
		}
	}
	return 0;
}