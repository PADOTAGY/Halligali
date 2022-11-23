#ifndef GAME_H
# define GAME_H

#include "../module.h"

typedef enum GameState { NotStart = 0, Start = 1, Pause = 2, Finished = 3 } GameState;
typedef enum GameMode { RuleChanged = 0, Start = 1, Pause = 2, Finished = 3 } GameState;

typedef struct Game {
	GameState state;
	NPC *npc;
	User *user;
	int mode;
	int key;
	int who;
	int gameCnt;
	int drawCnt;
	double playTime;
} Game;


#endif