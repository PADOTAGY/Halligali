#include "Card.h"
#include "Reusable.h"

int ringBell(struct Player player)
{
    int countAll = game->user.leftCardSet->count + game->user.rightCardSet->count + game->npc.leftCardSet->count + game->npc.rightCardSet->count;
    int sum[4] = {0};
    if (game->user.leftCardSet->count > 0)
    {
        sum[game->user.leftCardSet->root->id / 5] += game->user.leftCardSet->root->id % 5 + 1;
    }

    if (game->user.rightCardSet->count > 0)
    {
        sum[game->user.rightCardSet->root->id / 5] += game->user.rightCardSet->root->id % 5 + 1;
    }

    if (game->npc.leftCardSet->count > 0)
    {
        sum[game->npc.leftCardSet->root->id / 5] += game->npc.leftCardSet->root->id % 5 + 1;
    }

    if (game->npc.rightCardSet->count > 0)
    {
        sum[game->npc.rightCardSet->root->id / 5] += game->npc.rightCardSet->root->id % 5 + 1;
    }

    if ((sum[0] % 5 == 0 && sum[0] != 0) || (sum[1] % 5 == 0 && sum[1] != 0) || (sum[2] % 5 == 0 && sum[2] != 0) || (sum[3] % 5 == 0 && sum[3] != 0))
    {
        if (player.originCardSet->count == 0)
        {
            player.originCardSet->root = mergedCardSet();
        }
        else
        {
            struct Card *p = getCard(player.originCardSet, player.originCardSet->count - 1);
            p->next = mergedCardSet();
        }

        player.originCardSet->count += countAll;
    }
    else
    {
        penalty(player);
    }
}
struct Card *getCard(struct CardSet *S, int n)
{ // n번째 카드를 찾아주는 함수 (n >= 0)
    struct Card *p = S->root;
    for (int i = 0; i < n; i++)
    {
        p = p->next;
    }
    return p;
}
struct Card *mergedCardSet()
{
    struct CardSet *userL = game->user.leftCardSet, *userR = game->user.rightCardSet, *npcL = game->npc.leftCardSet, *npcR = game->npc.rightCardSet;
    struct Card *returnedCard = NULL, *currentCard;
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
void penalty(struct Player player)
{
    if (player.originCardSet->count == 0)
    {
        return;
    }
    struct Card *tmp;
    tmp = player.originCardSet->root;
    player.originCardSet->root = player.originCardSet->root->next;
    struct Card *p;
    if (player.id == NPC)
    {
        if (game->user.originCardSet->count >= 1)
        {
            p = getCard(game->user.originCardSet, game->user.originCardSet->count - 1);
            p->next = tmp;
        }
        else
        {
            game->user.originCardSet->root = tmp;
        }
        game->user.originCardSet->count++;
    }
    else
    {
        if (game->npc.originCardSet->count >= 1)
        {
            p = getCard(game->npc.originCardSet, game->npc.originCardSet->count - 1);
            p->next = tmp;
        }
        else
        {
            game->npc.originCardSet->root = tmp;
        }
        game->npc.originCardSet->count++;
    }
    player.originCardSet->count--;
}