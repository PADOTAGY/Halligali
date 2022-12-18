#ifndef REUSABLE_H
#define REUSABLE_H

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <time.h>
#include <conio.h>
#include <mmsystem.h>

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define SPACE 32
#define ESC 27

#define POP_SOUND ".\\..\\Resource\\Sound\\pop.wav"
#define BELL_SOUND ".\\..\\Resource\\Sound\\bell.wav"
#define ITEM_GET_SOUND ".\\..\\Resource\\Sound\\bbiyoung.wav"
#define BOMB_SOUND ".\\..\\Resource\\Sound\\bomb.wav"
#define FANFARE_SOUND ".\\..\\Resource\\Sound\\fanfare.wav"
#define NOPE_SOUND ".\\..\\Resource\\Sound\\nope.wav"
#define RULL_CHANGE_SOUND ".\\..\\Resource\\Sound\\rullchange.wav"
#define STAR_SOUND ".\\..\\Resource\\Sound\\star.wav"

#define cardsNum 62 

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
    LIME_FIVE = 19,
    BLUEBERRY_ONE = 20,
    BLUEBERRY_TWO = 21,
    BLUEBERRY_THREE = 22,
    BLUEBERRY_FOUR = 23,
    BLUEBERRY_FIVE = 24,
    BLOCK = 25
} CardId;

typedef struct CardSet
{
    struct Card *root;
    int count;
} CardSet;

typedef struct Card
{
    CardId id;
    struct Card *next; // struct Card *prev 삭제
} Card;

typedef enum ItemId
{
    RuleChangeItemId = 0,
    StarItemId = 1,
    BombItemId = 2,
    WinItemId = 3
} ItemId;

typedef enum ItemState
{
    Active = 0,
    Inactive = 1,
    Deleted = 2
} ItemState;

typedef struct Item
{
    ItemId id;
    ItemState state;
    int drawCnt;
} Item;

typedef struct User
{
    CardSet *originCardSet;
    CardSet *leftCardSet;
    CardSet *rightCardSet;
    Item *item;
    int score;
} User;

typedef struct NPC
{
    struct CardSet *originCardSet;
    struct CardSet *leftCardSet;
    struct CardSet *rightCardSet;
    int score;
    double timePutDownBell;
    int isMissPutDownBell;

    double avgTimeUserPutDownBell;
    double totalTimeUserPutDownBell;
    double tmpAvgTimeUserPutDownBell;
    int cntUserPutDownBell; // getTimeUserPutDownBell 실행 시마다 +1
} NPC;

typedef enum GameState
{
    NotStart = 0,
    Start = 1,
    Pause = 2,
    End = 3
} GameState;

typedef struct Game
{
    GameState state; // NotStart, Start, Pause, End
    NPC *npc;
    User *user;
    int missionId;
    int key;     // LEFT_KEY, RIGHT_KEY, UP_KEY, SPACE_KEY
    int who;     // user = 0, npc = 1
    int gameCnt; // 0, 1, ..., 무한
    int drawCnt;
    int whoBell; //안 치면 -1, user가 치면 0, npc가 치면 1
    double playTime;
    int sleepMs;
    double lastTime; //시간
} Game;

int getRandomInt(int start, int end);

#endif