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

static void drawTurnArrow(int who)
{
    int i = 0;
    static int beforeWho;

    if (who == beforeWho)
        return;

        
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);   
    if (who == 1) // 아직 안댐 왜냐하면 NPC가 자기 턴 처리하고 who를 다시 바꿈
    {
        i = 26;
        printOnPos("         ", 10, i++);
        printOnPos("         ", 10, i++);
        printOnPos("         ", 10, i++);
        printOnPos("         ", 10, i++);
        printOnPos("         ", 10, i++);
        printOnPos("         ", 10, i++);
        printOnPos("         ", 10, i++);
        printOnPos("         ", 10, i++);
        i = 26;
        printOnPos("    .", 10, i++);
        printOnPos("  .:;:.", 10, i++);
        printOnPos(".:;;;;;:.", 10, i++);
        printOnPos("  ;;;;;", 10, i++);
        printOnPos("  ;;;;;", 10, i++);
        printOnPos("  ;;;;;", 10, i++);
        printOnPos("  ;;;;;", 10, i++);
        printOnPos("  ;:;;;", 10, i++);
    }
    else
    {
        i = 26;
        printOnPos("         ", 10, i++);
        printOnPos("         ", 10, i++);
        printOnPos("         ", 10, i++);
        printOnPos("         ", 10, i++);
        printOnPos("         ", 10, i++);
        printOnPos("         ", 10, i++);
        printOnPos("         ", 10, i++);
        printOnPos("         ", 10, i++);
        i = 26;
        printOnPos("  ;;;;;", 10, i++);
        printOnPos("  ;;;;;", 10, i++);
        printOnPos("  ;;;;;", 10, i++);
        printOnPos("  ;;;;;", 10, i++);
        printOnPos("  ;;;;;", 10, i++);
        printOnPos("..;;;;;..", 10, i++);
        printOnPos(" ':::::'", 10, i++);
        printOnPos("   ':`", 10, i++);
   }
}

void updateUI(Game *game)
{
    static int NPCCnt;

    updateCard(game);
    drawTurnArrow(game->who);

    if (game->key == SPACE)
        drawHitBellMotion(1);
    else
        drawHitBellMotion(0);

    if (game->whoBell == 1)
        drawHitBellMotionNPC(1);
    else
        drawHitBellMotionNPC(0);

    
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    printOnPos("", 212, 0);         // for test
    printf("NPC Hit %d", NPCCnt++); //
    printOnPos("", 212, 8);//
    printf("game->playTime %.2f ", game->playTime);//
    printOnPos("", 212, 9);//
    printf("game->lastTime %.2f ", game->lastTime);//
    printOnPos("", 212, 2);//
    printf("Item id %d, state %d", game->user->item->id, game->user->item->state);//
    printOnPos("", 212, 3);//
    printf("user Card orign cnt %d ", game->user->originCardSet->count);//
    printOnPos("", 212, 4);//
    printf("npc Card orign cnt %d ", game->npc->originCardSet->count);//
    printOnPos("", 212, 5);//
    printf("tmpAvgTime %.2f ", game->npc->tmpAvgTimeUserPutDownBell);//
    printOnPos("", 212, 6);//
    printf("totalTime %.2f ", game->npc->totalTimeUserPutDownBell);//
    printOnPos("", 212, 7);//
    printf("cntUserPutDownBell %d ", game->npc->cntUserPutDownBell);//
    
}