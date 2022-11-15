#ifndef game_H
# define game_H

#include "../module.h"

typedef enum GameState { NotStart = 0, Start = 1, Pause = 2, Finished = 3 } GameState;

typedef struct Game {
	GameState state;
	User *user;
	int round;
} Game;

#endif