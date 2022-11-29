#include "game.h"

Game *initGame()
{
	srand((unsigned int)time(NULL));
	// GAME
	Game *game = (Game *)malloc(sizeof(Game));
	game->who = 0;
	game->whoBell = -1;
	game->state = NotStart;
	game->gameCnt = 0;
	game->drawCnt = 0;
	game->playTime = 0.0;
	game->sleepMs = 20;

	// USER
	game->user = (User *)malloc(sizeof(User));
	game->user->item = NULL;
	game->user->score = 0;

	// NPC
	game->npc = (NPC *)malloc(sizeof(NPC));
	game->npc->totalTimeUserPutDownBell = 0;
	game->npc->tmpAvgTimeUserPutDownBell=500;
	game->npc->cntUserPutDownBell = 0;
	game->npc->score = 0;

	// CARD
	game->user->originCardSet = (struct CardSet *)malloc(sizeof(struct CardSet));
	game->user->leftCardSet = (struct CardSet *)malloc(sizeof(struct CardSet));
	game->user->rightCardSet = (struct CardSet *)malloc(sizeof(struct CardSet));
	game->npc->originCardSet = (struct CardSet *)malloc(sizeof(struct CardSet));
	game->npc->leftCardSet = (struct CardSet *)malloc(sizeof(struct CardSet));
	game->npc->rightCardSet = (struct CardSet *)malloc(sizeof(struct CardSet));

	// UI
	drawScreen();

	return game;
}