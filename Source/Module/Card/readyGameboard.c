#include "card.h"

void readyGameboard(Game *game)
{
    CardId cards[56];
    makeDeck(cards);                           //덱 리스트를 만들고
    shuffle(cards);                            //셔플한 후
    devideBytwo(game->user, game->npc, cards); //덱 리스트를 두 개의 단일 연결리스트로 분할합니다.
}

void makeDeck(CardId cards[])
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
void shuffle(CardId cards[])
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

void devideBytwo(User *user, NPC *npc, CardId cards[])
{
    user->originCardSet->root = makeCard(cards[0]);
    npc->originCardSet->root = makeCard(cards[28]);
    Card *p = user->originCardSet->root, *q = npc->originCardSet->root;
    for (int i = 1; i < 28; i++)
    {
        p->next = makeCard(cards[i]);
        p = p->next;
        q->next = makeCard(cards[i + 28]);
        q = q->next;
    }
    user->originCardSet->count = 28;
    npc->originCardSet->count = 28;
    user->leftCardSet->count = 0;
    user->rightCardSet->count = 0;
    npc->leftCardSet->count = 0;
    npc->rightCardSet->count = 0;
}

Card *makeCard(int cardId)
{
    Card *newCard;
    newCard = (Card *)malloc(sizeof(Card));
    newCard->id = cardId;
    newCard->next = NULL;
    return newCard;
}