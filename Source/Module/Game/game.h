#ifndef GAME_H
#define GAME_H

#include "../Reusable/Reusable.h"
#include "../Item/item.h"

#define LEFT_KEY 75
#define RIGHT_KEY 77
#define UP_KEY 72
#define SPACE_KEY 32

Game *initGame();
void makeStartPage();
void makeEndPage();
void updateMissionId(Game *game);
int getRandomMissionId();
#endif