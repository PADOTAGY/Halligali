#include "UI.h"

static void updateCard(Game *game)
{
    static userLeftCardSetCnt;
    static userRightCardSetCnt;
    static npcLeftCardSetCnt;
    static npcRightCardSetCnt;

    if (game->user->leftCardSet->count == 0)
        ; // deleteCard(CARD_POS_X_PERSON_L, CARD_POS_X_PERSON_L);
    else if (userLeftCardSetCnt != game->user->leftCardSet->count)
        drawCard(game->user->leftCardSet->root->id, CARD_POS_X_PERSON_L, CARD_POS_X_PERSON_L);
    userLeftCardSetCnt = game->user->leftCardSet->count;

    if (game->user->rightCardSet->count == 0)
        ; // deleteCard(CARD_POS_X_PERSON_R, CARD_POS_X_PERSON_R);
    else if (userRightCardSetCnt != game->user->rightCardSet->count)
        drawCard(game->user->rightCardSet->root->id, CARD_POS_X_PERSON_R, CARD_POS_X_PERSON_R);
    userRightCardSetCnt = game->user->rightCardSet->count;

    if (game->npc->leftCardSet->count == 0)
        ; // deleteCard(CARD_POS_X_NPC_L, CARD_POS_X_NPC_L);
    else if (npcLeftCardSetCnt != game->npc->leftCardSet->count)
        drawCard(game->npc->leftCardSet->root->id, CARD_POS_X_NPC_L, CARD_POS_X_NPC_L);
    npcLeftCardSetCnt = game->npc->leftCardSet->count;

    if (game->npc->rightCardSet->count == 0)
        ; // deleteCard(CARD_POS_X_NPC_R, CARD_POS_X_NPC_R);
    else if (npcRightCardSetCnt != game->npc->rightCardSet->count)
        drawCard(game->npc->rightCardSet->root->id, CARD_POS_X_NPC_R, CARD_POS_X_NPC_R);
    npcRightCardSetCnt = game->npc->rightCardSet->count;
}

void updateUI(Game *game)
{
    updateCard(game);
    if (game->key == SPACE)
        drawHitBellMotion(1);
    drawHitBellMotion(0);
}