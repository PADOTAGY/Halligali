#include "Card.h"

void readyGameboard()
{
    makeDeck(); //덱 리스트를 만들고
    shuffle();  //셔플한 후
    devideBytwo();  //덱 리스트를 두 개의 단일 연결리스트로 분할합니다.
}

void makeDeck()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cards[i * 14 + j] = STRAWBERRY_ONE + 5 * i;
        }
        for (int j = 5; j < 8; j++)
        {
            cards[i * 14 + j] = STRAWBERRY_TWO + 5 * i;
        }
        for (int j = 8; j < 11; j++)
        {
            cards[i * 14 + j] = STRAWBERRY_THREE + 5 * i;
        }
        for (int j = 11; j < 13; j++)
        {
            cards[i * 14 + j] = STRAWBERRY_FOUR + 5 * i;
        }
        cards[i * 14 + 13] = STRAWBERRY_FIVE + 5 * i;
    }
}
void shuffle()
{
    int i = 56;
    while (i > 1)
    {
        swap(&(cards[rand() % i]), &(cards[i - 1]));
        i--;
    }
}
void swap(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void devideBytwo()
{
    game->user.originCardSet->root = makeCard(cards[0]);
    game->npc.originCardSet->root = makeCard(cards[28]);
    struct Card *p = game->user.originCardSet->root, *q = game->npc.originCardSet->root;
    for (int i = 1; i < 28; i++)
    {
        p->next = makeCard(cards[i]);
        p = p->next;
        q->next = makeCard(cards[i + 28]);
        q = q->next;
    }
    game->user.originCardSet->count = 28;
    game->npc.originCardSet->count = 28;
    game->user.leftCardSet->count = 0;
    game->user.rightCardSet->count = 0;
    game->npc.leftCardSet->count = 0;
    game->npc.rightCardSet->count = 0;
}

struct Card *makeCard(int cardId)
{
    struct Card *newCard;
    newCard = (struct Card *)malloc(sizeof(struct Card));
    newCard->id = cardId;
    newCard->next = NULL;
    return newCard;
}