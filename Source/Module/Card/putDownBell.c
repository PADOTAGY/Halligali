#include "card.h"

void putDownBell(Game *game)
{
    game->whoBell = 0;
    int countAll = game->user->leftCardSet->count + game->user->rightCardSet->count + game->npc->leftCardSet->count + game->npc->rightCardSet->count;
    if (game->whoBell == 0)
    {
        if (isActiveBombItem(game->user->item))
        {
            // nothing
            
        }
        else if (isNiceBell(game))
        {
            int cardId = isNiceBell(game);
            if (cardId - 1 == game->missionId) {
                updateMissionId(game);
                updateRandomItem(game);
            }
            
            if (game->user->originCardSet->count == 0)
            {
                game->user->originCardSet->root = mergedCardSet(game);
            }
            else
            {
                struct Card *p = getCard(game->user->originCardSet, game->user->originCardSet->count - 1);
                p->next = mergedCardSet(game);
            }
            game->user->originCardSet->count += countAll;
            calcAverageTimeUserPutDownBell(game, game->npc);
        }
        else
        {
            penaltyUser(game);
        }

        // game->who = 0; // user가 종치면 다음 user턴
    }
    // else
    // {
    //     if (isNiceBell(game))
    //     {
    //         if (game->npc->originCardSet->count == 0)
    //         {
    //             game->npc->originCardSet->root = mergedCardSet(game);
    //         }
    //         else
    //         {
    //             struct Card *p = getCard(game->npc->originCardSet, game->npc->originCardSet->count - 1);
    //             p->next = mergedCardSet(game);
    //         }
    //         game->npc->originCardSet->count += countAll;
    //     }
    //     else
    //     {
    //         penaltyNPC(game);
    //     }
    // }
}

int isNiceBell(Game *game)
{
    int sum[6] = {0};
    if (game->whoBell == 0 && isActiveWinItem(game->user->item))
        return 999;

    if (game->user->leftCardSet->count > 0)
        sum[game->user->leftCardSet->root->id / 5] += game->user->leftCardSet->root->id % 5 + 1;
    if (game->user->rightCardSet->count > 0)
        sum[game->user->rightCardSet->root->id / 5] += game->user->rightCardSet->root->id % 5 + 1;
    if (game->npc->leftCardSet->count > 0)
        sum[game->npc->leftCardSet->root->id / 5] += game->npc->leftCardSet->root->id % 5 + 1;
    if (game->npc->rightCardSet->count > 0)
        sum[game->npc->rightCardSet->root->id / 5] += game->npc->rightCardSet->root->id % 5 + 1;

    if (game->whoBell == 0 && isActiveRuleChangeItem(game->user->item))
    {
        for (int i = 0; i < 4; i++)
            if (((sum[4] + sum[i]) % 5 == 0 || (sum[4] + sum[i]) % 3 == 0) && sum[4] + sum[i] != 0)
                return (i + 1);
        return 0; 
    }
    else
    {
        for (int i = 0; i < 4; i++)
            if ((sum[4] + sum[i]) % 5 == 0 && sum[4]+sum[i] != 0)
                return (i + 1);
        return 0;
    }
}

// int ringBell(Game *game)
// {
//     int countAll = game->user->leftCardSet->count + game->user->rightCardSet->count + game->npc->leftCardSet->count + game->npc->rightCardSet->count;
//     int sum[4] = {0};
//     if (game->user->leftCardSet->count > 0)
//     {
//         sum[game->user->leftCardSet->root->id / 5] += game->user->leftCardSet->root->id % 5 + 1;
//     }

//     if (game->user->rightCardSet->count > 0)
//     {
//         sum[game->user->rightCardSet->root->id / 5] += game->user->rightCardSet->root->id % 5 + 1;
//     }

//     if (game->npc->leftCardSet->count > 0)
//     {
//         sum[game->npc->leftCardSet->root->id / 5] += game->npc->leftCardSet->root->id % 5 + 1;
//     }

//     if (game->npc->rightCardSet->count > 0)
//     {
//         sum[game->npc->rightCardSet->root->id / 5] += game->npc->rightCardSet->root->id % 5 + 1;
//     }

//     if ((sum[0] % 5 == 0 && sum[0] != 0) || (sum[1] % 5 == 0 && sum[1] != 0) || (sum[2] % 5 == 0 && sum[2] != 0) || (sum[3] % 5 == 0 && sum[3] != 0))
//     {
//         if(game->whoBell == 0){
//             NPC *player = game->npc;
//             if (player.originCardSet->count == 0)
//             {
//                 player.originCardSet->root = mergedCardSet();
//             }
//             else
//             {
//                 struct Card *p = getCard(player.originCardSet, player.originCardSet->count - 1);
//                 p->next = mergedCardSet();
//             }
//             player.originCardSet->count += countAll;
//         }
//         else{
//             User *player = game->user;
//             if (player.originCardSet->count == 0)
//             {
//                 player.originCardSet->root = mergedCardSet();
//             }
//             else
//             {
//                 struct Card *p = getCard(player.originCardSet, player.originCardSet->count - 1);
//                 p->next = mergedCardSet();
//             }
//             player.originCardSet->count += countAll;
//         }

//     }
//     else
//     {
//         if(game->whoBell == 0)
//             penalty();
//         else{
//             penalty()
//         }
//     }
// }
struct Card *getCard(struct CardSet *S, int n)
{ // n번째 카드를 찾아주는 함수 (n >= 0)
    struct Card *p = S->root;
    for (int i = 0; i < n; i++)
    {
        p = p->next;
    }
    return p;
}

Card *mergedCardSet(Game *game)
{
    CardSet *userL = game->user->leftCardSet, *userR = game->user->rightCardSet, *npcL = game->npc->leftCardSet, *npcR = game->npc->rightCardSet;
    Card *returnedCard = NULL, *currentCard;
    int i = 4;
    int a = 0, b = 1, c = 2, d = 3;
    while (1)
    {
        if (userL->count == 0 && a >= 0)
        {
            a = -1;
            b--;
            c--;
            d--;
            i--;
        }
        if (userR->count == 0 && b >= 0)
        {
            b = -1;
            c--;
            d--;
            i--;
        }
        if (npcL->count == 0 && c >= 0)
        {
            c = -1;
            d--;
            i--;
        }
        if (npcR->count == 0 && d >= 0)
        {
            d = -1;
            i--;
        }
        if (i == 0)
        {
            break;
        }
        int index = rand() % i;
        struct Card *tmp;
        if (index == a)
        {
            tmp = userL->root;
            userL->root = userL->root->next;
            userL->count--;
        }
        else if (index == b)
        {
            tmp = userR->root;
            userR->root = userR->root->next;
            userR->count--;
        }
        else if (index == c)
        {
            tmp = npcL->root;
            npcL->root = npcL->root->next;
            npcL->count--;
        }
        else if (index == d)
        {
            tmp = npcR->root;
            npcR->root = npcR->root->next;
            npcR->count--;
        }
        if (returnedCard == NULL)
        {
            returnedCard = tmp;
            currentCard = returnedCard;
        }
        else
        {
            currentCard->next = tmp;
            currentCard = currentCard->next;
        }
    }
    return returnedCard;
}
void penaltyUser(Game *game)
{
    if (isActiveStarItem(game->user->item))
        return;

    if (game->user->originCardSet->count == 0)
    {
        return;
    }
    Card *tmp;
    tmp = game->user->originCardSet->root;
    game->user->originCardSet->root = game->user->originCardSet->root->next;
    Card *p;
    if (game->npc->originCardSet->count >= 1)
    {
        p = getCard(game->npc->originCardSet, game->npc->originCardSet->count - 1);
        p->next = tmp;
    }
    else
    {
        game->npc->originCardSet->root = tmp;
    }
    game->npc->originCardSet->count++;
    game->user->originCardSet->count--;
}

void penaltyNPC(Game *game)
{
    if (game->npc->originCardSet->count == 0)
    {
        return;
    }
    Card *tmp;
    tmp = game->npc->originCardSet->root;
    game->npc->originCardSet->root = game->npc->originCardSet->root->next;
    Card *p;
    if (game->user->originCardSet->count >= 1)
    {
        p = getCard(game->user->originCardSet, game->user->originCardSet->count - 1);
        p->next = tmp;
    }
    else
    {
        game->user->originCardSet->root = tmp;
    }
    game->npc->originCardSet->count++;
    game->npc->originCardSet->count--;
}
