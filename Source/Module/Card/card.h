#ifndef CARD_H
#define CARD_H

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define SPACE 32
#define ESC 27

typedef enum GameState
{
    Ready = 0,
    Playing = 1,
    End = 2
} GameState;
typedef enum PlayerId
{
    NPC = 0,
    USER = 1
} PlayerId;
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
typedef enum ItemId
{
    BOMB = 0,
    GOD = 1
} ItemId;
typedef enum ItemState
{
    Active = 0,
    Inactive = 1,
    Deleted = 2
} ItemState;

struct Player
{
    PlayerId id;
    int point;
    struct CardSet *originCardSet;
    struct CardSet *leftCardSet;
    struct CardSet *rightCardSet;
    struct Item *item; // ItemSet *itemSet -> Item *item 으로 변경
} Player;

struct Game
{
    GameState state;
    struct Player user;
    struct Player npc;
    int round;
};

struct CardSet
{
    struct Card *root;
    int count;
};
struct Card
{
    CardId id;
    struct Card *next; // struct Card *prev 삭제
};
struct ItemSet
{
    struct Item *root;
    int count;
};
struct Item
{
    ItemId id;
    ItemState state;
    int roundCount;
};

void makeDeck();
void shuffle();
void swap();
void devideBytwo();
void readyGameboard();
struct Card *makeCard(int cardId);

void drawCard(struct Player player, int pos);

int ringBell(struct Player player);
struct Card *getCard(struct CardSet *S, int n);
struct Card *mergedCardSet();

int isEndGame();
int whoIsWinner();

CardId cards[56];
struct Game *game;
#endif