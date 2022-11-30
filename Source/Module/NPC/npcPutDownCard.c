#include "NPC.h"

void npcPutDownCard(Game *game)
{
   game->npc->advantage = checkIsNPCAdvantage(game);
   if (game->npc->advantage) // npc advantage일 때
   {
      npcPutDownCardAdvantage(game);
   }
   else // npc advantage아닐 때
   {
      npcPutDownCardNotAdvantage(game);
   }
}

// npc가 advantage일 때 카드 내려놓기
void npcPutDownCardAdvantage(Game *game)
{
   raiseDifficultyNPCAdvantage(game);
   // Sleep(game->npc->tmpAvgTimeUserPutDownBell* 1000);

   if (game->npc->advantage == 1) // npc왼쪽 카드더미에서 5가 나온다면
   {
      putDownCard(game->npc->originCardSet, game->npc->leftCardSet);
      game->lastTime = game->playTime;
      game->who = 0;
   }

   else if (game->npc->advantage == 2) // npc오른쪽 카드더미에서 5가 나온다면
   {
      putDownCard(game->npc->originCardSet, game->npc->rightCardSet);
      game->lastTime = game->playTime;
      game->who = 0;
   }
}

// npc가 not advantage일 때 카드 내려놓기
void npcPutDownCardNotAdvantage(Game *game)
{
   int ranpos;
   ranpos = rand() % 2; //왼쪽,오른쪽 자리 선택

   if (ranpos == 0) // NPC오른쪽에 카드 놓기
   {
      putDownCard(game->npc->originCardSet, game->npc->rightCardSet);
      game->lastTime = game->playTime;
      game->who = 0;
   }
   else if (ranpos == 1) // NPC왼쪽에 카드 놓기
   {
      putDownCard(game->npc->originCardSet, game->npc->leftCardSet);
      game->lastTime = game->playTime;
      game->who = 0;
   }
}