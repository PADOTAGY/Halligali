#include "UI.h"

static void updateCard(Game *game)
{
    static int userLeftCardSetCnt;
    static int userRightCardSetCnt;
    static int npcLeftCardSetCnt;
    static int npcRightCardSetCnt;

    static int lastPutDownedCard; // 마지막에 카드를 놓은 위치 : 초록색으로 표시

    if (userLeftCardSetCnt < game->user->leftCardSet->count)
    {
        lastPutDownedCard = 7;
        PlaySound(TEXT(POP_SOUND), NULL, SND_ASYNC);
    }
    else if (userRightCardSetCnt < game->user->rightCardSet->count)
    {
        lastPutDownedCard = 4;
        PlaySound(TEXT(POP_SOUND), NULL, SND_ASYNC);
    }
    else if (npcLeftCardSetCnt < game->npc->leftCardSet->count)
    {
        lastPutDownedCard = 11;
        PlaySound(TEXT(POP_SOUND), NULL, SND_ASYNC);
    }
    else if (npcRightCardSetCnt < game->npc->rightCardSet->count)
    {
        lastPutDownedCard = 1;
        PlaySound(TEXT(POP_SOUND), NULL, SND_ASYNC);
    }

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
    printOnPos("", CARD_POS_X_PERSON_R, CARD_POS_Y_PERSON_R - 2);
    if (userRightCardSetCnt == 0)
        printf("  ");
    else
        printf("%2d", userRightCardSetCnt);
    printOnPos("", CARD_POS_X_NPC_L - 2 + 20, CARD_POS_Y_NPC_L + 16);
    if (npcLeftCardSetCnt == 0)
        printf("  ");
    else
        printf("%2d", npcLeftCardSetCnt);
    printOnPos("", CARD_POS_X_NPC_R, CARD_POS_Y_NPC_R + 16);
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
        printOnPos("", CARD_POS_X_PERSON_R, CARD_POS_Y_PERSON_R - 2);
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
        printOnPos("", CARD_POS_X_NPC_R, CARD_POS_Y_NPC_R + 16);
        if (npcRightCardSetCnt == 0)
            printf("  ");
        else
            printf("%2d", npcRightCardSetCnt);
    }
}

static void drawTurnBlock(int who)
{
    int i = 0;
    static int beforeWho = -1;

    if (who == beforeWho)
        return;

    if (who == 1)
    {
        for (int i = 31; i < 45; i++)
        {
            printOnPos("  ", 60, i);
            printOnPos("  ", 178, i);
        }
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
        printOnPos("■■■■■■■■■■■■■■■■■■■ ", 60, 30);
        printOnPos("■■■■■■■■■■■■■■■■■■■ ", 142, 30);
        for (int i = 29; i > 15; i--)
        {
            printOnPos("■ ", 60, i);
            printOnPos("■ ", 178, i);
        }
    }
    else
    {
        for (int i = 29; i > 15; i--)
        {
            printOnPos("  ", 60, i);
            printOnPos("  ", 178, i);
        }
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        printOnPos("■■■■■■■■■■■■■■■■■■■ ", 60, 30);
        printOnPos("■■■■■■■■■■■■■■■■■■■ ", 142, 30);
        for (int i = 31; i < 45; i++)
        {
            printOnPos("■ ", 60, i);
            printOnPos("■ ", 178, i);
        }
    }
    beforeWho = who;
}

void updateItem(Game *game)
{
    static ItemId beforeItemId = 0;
    static GameState beforeState = Deleted;
    static int beforeMissionId = -1;

    if (beforeMissionId == game->missionId)
        return ;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
    switch (game->missionId ) {
        case 0:
            printOnPos("딸기로 승리하세요.    ", 239 - 30 + 2, 24);
            break;
        case 1:
            printOnPos("바나나로 승리하세요.   ", 239 - 30 + 2, 24);
            break;
        case 2:
            printOnPos("자두로 승리하세요.  ", 239 - 30 + 2, 24);
            break;
        case 3:
            printOnPos("라임으로 승리하세요.  ", 239 - 30 + 2, 24);
            break;
    }
    
    if (game->user->item == NULL)
        return ;

    if (beforeItemId == game->user->item->id && beforeState == game->user->item->state)
        return ;

    deleteItem(ITEM_POS_X, ITEM_POS_Y);
    if (game->user->item->state == Deleted) {
        printOnPos("                           ", 239 - 30 + 2, ITEM_POS_Y + 2);
        printOnPos("                           ", 239 - 30 + 2, ITEM_POS_Y + 4);
        printOnPos("                           ", 239 - 30 + 2, ITEM_POS_Y + 8);
        printOnPos("                           ", 239 - 30 + 2, ITEM_POS_Y + 10);
    } else {
        drawItem(game->user->item, ITEM_POS_X, ITEM_POS_Y);
    }

    beforeItemId = game->user->item->id;
    beforeState = game->user->item->state;
}

void printStates(Game *game)
{
    static int NPCCnt;
    static int userCardSetCnt;
    static int NPCCardSetCnt;

    if (userCardSetCnt == game->user->originCardSet->count && NPCCardSetCnt == game->npc->originCardSet->count)
        return ;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    printOnPos("", 212, 0);                                                    
    printf("NPC Hit %d", NPCCnt);                                                  
    printOnPos("", 212, 8);                          
    printf("game->lastTime %.2f ", game->lastTime);                                
    printOnPos("", 212, 2);                                                        
    if (game->user->item != NULL)
        printf("Item id %d, state %d drawCnt %d", game->user->item->id, game->user->item->state, game->user->item->drawCnt); 
    printOnPos("", 212, 3);                                                        
    printf("user Card orign cnt %d ", game->user->originCardSet->count);           
    printOnPos("", 212, 4);                                                        
    printf("npc Card orign cnt %d ", game->npc->originCardSet->count);             
    printOnPos("", 212, 5);                                                        
    printf("tmpAvgTime %.2f ", game->npc->tmpAvgTimeUserPutDownBell);              
    printOnPos("", 212, 7);                                                        
    printf("cntUserPutDownBell %d ", game->npc->cntUserPutDownBell);  
    printOnPos("", 212, 6);                                                        
    printf("totalTime %.2f ", game->npc->totalTimeUserPutDownBell);                
 

    userCardSetCnt = game->user->originCardSet->count;
    NPCCardSetCnt = game->npc->originCardSet->count;
}

void updateUI(Game *game)
{
    updateCard(game);
    updateCardSetNumber(game);
    drawTurnBlock(game->who);
    updateItem(game);

    
    if (game->key == SPACE || game->whoBell == 1)
        reDrawBell(1);
    else
        reDrawBell(0);

    if (game->key == SPACE)
        drawHitBellMotion(1);
    else
        drawHitBellMotion(0);

    if (game->whoBell == 1)
        drawHitBellMotionNPC(1);
    else
        drawHitBellMotionNPC(0);


    printStates(game);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    printOnPos("", 212, 8);
    printf("game->playTime %.2f ", game->playTime); 
}
