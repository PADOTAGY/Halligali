#ifndef NPC_H
# define NPC_H

# include <stdio.h>
# include <Windows.h>
# include <time.h>
//# include "../module.h"

double getTimeWhenNPCDrawCard(void);
double returnTimeInput(void)

//아래의 구조체들은 추후에 card.h와 game.h 중 하나로 정한 후 헤더파일 선언할 예정
struct Player
{
    PlayerId id;
    int point;
    struct CardSet* originCardSet;
    struct CardSet* leftCardSet;
    struct CardSet* rightCardSet;
    struct Item* item; // ItemSet *itemSet -> Item *item 으로 변경
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
    struct Card* root;
    int count;
};
struct Card
{
    CardId id;
    struct Card* next; // struct Card *prev 삭제
};
struct ItemSet
{
    struct Item* root;
    int count;
};
struct Item
{
    ItemId id;
    ItemState state;
    int roundCount;
};

#endif