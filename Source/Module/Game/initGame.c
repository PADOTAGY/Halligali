#include "game.h"

Game *initGame()
{
	// GAME
	Game *game = (Game *)malloc(sizeof(Game));
	game->state = NotStart;
	game->gameCnt = 0;
	game->drawCnt = 0;
	game->playTime = 0.0;

	// USER
	game->user = (User *)malloc(sizeof(User));
	game->user->item = NULL;
	game->user->score = 0;

	// NPC
	game->npc = (NPC *)malloc(sizeof(NPC));
	game->npc->AvgTimeUserPutDownBell = 0;
    game->npc->totalTimeUserPutDownBell = 0;
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
	initTerminal();
	return game;
}