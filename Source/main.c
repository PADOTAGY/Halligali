#include "Module/module.h"

int main()
{
	Game *game = initGame();
	
	while (1)
	{
		// 아이템
		runItemModule(game, 10);
		// 카드 내려놓기
		// 벨 누르기
		// NPC
		// 승리조건
		// UI update : upadateUI()
		Sleep(50);
	}
}