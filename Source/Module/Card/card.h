#ifndef CARD_H
#define CARD_H

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define SPACE 32
#define ESC 27

#include "../module.h"

typedef enum PlayerId { NpcId = 0, UserId = 1 } PlayerId;

typedef enum CardId
{
    STRAWBERRY_ONE = 0,
    STRAWBERRY_TWO = 1,
    STRAWBERRY_THREE = 2,
    STRAWBERRY_FOUR = 3,
    STRAWBERRY_FIVE = 4,
    BANANA_ONE = 5,
    BANANA_TWO = 6,
    BANANA_THREE = 7,
    BANANA_FOUR = 8,
    BANANA_FIVE = 9,
    PLUM_ONE = 10,
    PLUM_TWO = 11,
    PLUM_THREE = 12,
    PLUM_FOUR = 13,
    PLUM_FIVE = 14,
    LIME_ONE = 15,
    LIME_TWO = 16,
    LIME_THREE = 17,
    LIME_FOUR = 18,
    LIME_FIVE = 19
} CardId;

typedef struct CardSet
{
    struct Card *root;
    int count;
}CardSet;
typedef struct Card
{
    CardId id;
    struct Card *next; // struct Card *prev 삭제
}Card;

void makeDeck(CardId cards[]);
void shuffle(CardId cards[]);
void swap();
void devideBytwo(CardId cards[]);
void readyGameboard();
struct Card *makeCard(int cardId);
void penalty(struct Player player);

void putDownCard(struct Player player, int pos);

int ringBell(struct Player player);
struct Card *getCard(struct CardSet *S, int n);
struct Card *mergedCardSet();

int isEndGame();
int whoIsWinner();
void endGame();

#endif