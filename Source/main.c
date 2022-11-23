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
	while (1) {
        while (1) {
		getKey(game);
		// 아이템
		runItemModule(game, 10);
		// 카드 내려놓기
		// 벨 누르기
		// NPC
		// 승리조건
        
		updateUI(game);
        
        if (checkAndRunEndGame(game))
            break;
		game->key = 0;
		Sleep(50);
        }
    }
	return 0;
}