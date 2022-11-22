#ifndef NPC_H
# define NPC_H

# include <stdio.h>
# include <Windows.h>
# include <time.h>
//# include "../module.h"

double getTimeWhenNPCDrawCard(void);
double returnTimeInput(void)

//�Ʒ��� ����ü���� ���Ŀ� card.h�� game.h �� �ϳ��� ���� �� ������� ������ ����
struct Player
{
    PlayerId id;
    int point;
    struct CardSet* originCardSet;
    struct CardSet* leftCardSet;
    struct CardSet* rightCardSet;
    struct Item* item; // ItemSet *itemSet -> Item *item ���� ����
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
    struct Card* next; // struct Card *prev ����
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