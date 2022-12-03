#include "game.h"

int getRandomMissionId() {
    return getRandomInt(0, 3);
}

void updateMissionId(Game *game) {
    game->missionId = getRandomMissionId();
}
