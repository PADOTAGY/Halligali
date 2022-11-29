#include "UI.h"

static void updateCard(Game *game)
{
    static int userLeftCardSetCnt;
    static int userRightCardSetCnt;
    static int npcLeftCardSetCnt;
    static int npcRightCardSetCnt;

    static int lastPutDownedCard; // 마지막에 카드를 놓은 위치 : 초록색으로 표시

    if (userLeftCardSetCnt < game->user->leftCardSet->count)
        lastPutDownedCard = 7;
    else if (userRightCardSetCnt < game->user->rightCardSet->count)
        lastPutDownedCard = 4;
    else if (npcLeftCardSetCnt < game->npc->leftCardSet->count)
        lastPutDownedCard = 11;
    else if (npcRightCardSetCnt < game->npc->rightCardSet->count)
        lastPutDownedCard = 1;
    
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    // 7시
    if (game->user->leftCardSet->count == 0)
        deleteCard(CARD_POS_X_PERSON_L, CARD_POS_Y_PERSON_L);
    else if (userLeftCardSetCnt != game->user->leftCardSet->count)
        drawCard(game->user->leftCardSet->root->id, CARD_POS_X_PERSON_L, CARD_POS_Y_PERSON_L);
    userLeftCardSetCnt = game->user->leftCardSet->count;

    // 4시
    if (game->user->rightCardSet->count == 0)
        deleteCard(CARD_POS_X_PERSON_R, CARD_POS_Y_PERSON_R);
    else if (userRightCardSetCnt != game->user->rightCardSet->count)
        drawCard(game->user->rightCardSet->root->id, CARD_POS_X_PERSON_R, CARD_POS_Y_PERSON_R);
    userRightCardSetCnt = game->user->rightCardSet->count;

    // 11시
    if (game->npc->leftCardSet->count == 0)
        deleteCard(CARD_POS_X_NPC_L, CARD_POS_Y_NPC_L);
    else if (npcLeftCardSetCnt != game->npc->leftCardSet->count)
        drawCard(game->npc->leftCardSet->root->id, CARD_POS_X_NPC_L, CARD_POS_Y_NPC_L);
    npcLeftCardSetCnt = game->npc->leftCardSet->count;

    // 1시
    if (game->npc->rightCardSet->count == 0)
        deleteCard(CARD_POS_X_NPC_R, CARD_POS_Y_NPC_R);
    else if (npcRightCardSetCnt != game->npc->rightCardSet->count)
        drawCard(game->npc->rightCardSet->root->id, CARD_POS_X_NPC_R, CARD_POS_Y_NPC_R);
    npcRightCardSetCnt = game->npc->rightCardSet->count;
    

    // 덱별 카드수 출력
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	printOnPos("", CARD_POS_X_PERSON_L - 2 + 20, CARD_POS_Y_PERSON_L - 2);
    if (userLeftCardSetCnt == 0)
        printf("  ");
    else
        printf("%2d", userLeftCardSetCnt);
	printOnPos("", CARD_POS_X_PERSON_R  , CARD_POS_Y_PERSON_R - 2);
    if (userRightCardSetCnt == 0)
        printf("  ");
    else
        printf("%2d", userRightCardSetCnt);
	printOnPos("", CARD_POS_X_NPC_L - 2 + 20, CARD_POS_Y_NPC_L + 16);
    if (npcLeftCardSetCnt == 0)
        printf("  ");
    else
        printf("%2d", npcLeftCardSetCnt);
	printOnPos("", CARD_POS_X_NPC_R , CARD_POS_Y_NPC_R + 16);
    if (npcRightCardSetCnt == 0)
        printf("  ");
    else
        printf("%2d", npcRightCardSetCnt);

    //새로운 위치는 초록색
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
    if (lastPutDownedCard == 7)
    {
        printOnPos("", CARD_POS_X_PERSON_L - 2 + 20, CARD_POS_Y_PERSON_L - 2);
        if (userLeftCardSetCnt == 0)
            printf("  ");
        else
            printf("%2d", userLeftCardSetCnt);
    }
    else if (lastPutDownedCard == 4)
    {
        printOnPos("", CARD_POS_X_PERSON_R  , CARD_POS_Y_PERSON_R - 2);
        if (userRightCardSetCnt == 0)
            printf("  ");
        else
            printf("%2d", userRightCardSetCnt);
    }
    else if (lastPutDownedCard == 11)
    {
        printOnPos("", CARD_POS_X_NPC_L - 2 + 20, CARD_POS_Y_NPC_L + 16);
        if (npcLeftCardSetCnt == 0)
            printf("  ");
        else
            printf("%2d", npcLeftCardSetCnt);
    }
    else if (lastPutDownedCard == 1)
    {
        printOnPos("", CARD_POS_X_NPC_R , CARD_POS_Y_NPC_R + 16);
        if (npcRightCardSetCnt == 0)
            printf("  ");
        else
            printf("%2d", npcRightCardSetCnt);
    }
}

void updateUI(Game *game)
{
    static int NPCCnt;
    updateCard(game);

    if (game->key == SPACE)
        drawHitBellMotion(1);
    else
        drawHitBellMotion(0);

    if (game->whoBell == 1)
    {
        drawHitBellMotionNPC(1);
        printOnPos("", 120, 0);         // for test
        printf("NPC Hit %d", NPCCnt++); //
        printOnPos("", 120, 8);//
        printf("game->playTime %f ", game->playTime);//
        printOnPos("", 120, 9);//
        printf("game->lastTime %f ", game->lastTime);//
    }
    else
        drawHitBellMotionNPC(0);

    printOnPos("", 120, 2);//
    printf("Item id %d, state %d", game->user->item->id, game->user->item->state);//
    printOnPos("", 120, 3);//
    printf("user Card orign cnt %d ", game->user->originCardSet->count);//
    printOnPos("", 120, 4);//
    printf("npc Card orign cnt %d ", game->npc->originCardSet->count);//
    printOnPos("", 120, 5);//
    printf("tmpAvgTime %f ", game->npc->tmpAvgTimeUserPutDownBell);//
    printOnPos("", 120, 6);//
    printf("totalTime %f ", game->npc->totalTimeUserPutDownBell);//
    printOnPos("", 120, 7);//
    printf("cntUserPutDownBell %d ", game->npc->cntUserPutDownBell);//
    
}