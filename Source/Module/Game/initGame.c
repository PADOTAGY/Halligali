
#include "game.h"

Game *initGame()
{
	Game *game = (Game *)malloc(sizeof(Game));
	game->user = (User *)malloc(sizeof(User));
	game->state = NotStart;
	game->mode = Pause;
	game->round = 0;
	game->drawCnt = 0;
	game->playTime = 0.0;

	return game;
}