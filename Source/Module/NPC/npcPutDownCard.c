#include "NPC.h"

void npcPutDownCard(Game *game)
{
   int advantage = checkIsNPCAdvantage(game);
   if (advantage == 1) // npc advantage 왼쪽카드 내기
   {
      npcPutDownLeftCardAdvantage(game);
   }
   else if (advantage == 2) // npc advantage 오른쪽카드 내기
      npcPutDownRightCardAdvantage(game);

   else if (advantage == 0) // npc advantage아닐 때
   {
      npcPutDownCardNotAdvantage(game);
   }
}

// npc가 advantage일 때 카드 내려놓기
void npcPutDownLeftCardAdvantage(Game *game)
{
   
   //  Sleep(game->npc->tmpAvgTimeUserPutDownBell* 1000);

   putDownCard(game->npc->originCardSet, game->npc->leftCardSet);
   if(game->npc->leftCardSet->root->id == BLOCK){
      return;
   }
   //raiseDifficultyNPCAdvantage(game);
   game->who = 0;
   //game->lastTime = game->playTime;

   //returnRaiseDifficultyNPCAdvantage(game);
}

void npcPutDownRightCardAdvantage(Game *game)
{
   // raiseDifficultyNPCAdvantage(game);
   //  Sleep(game->npc->tmpAvgTimeUserPutDownBell* 1000);

   putDownCard(game->npc->originCardSet, game->npc->rightCardSet);
   if(game->npc->rightCardSet->root->id == BLOCK){
      return;
   }
   //raiseDifficultyNPCAdvantage(game);
   game->who = 0;
   //game->lastTime = game->playTime;

   //returnRaiseDifficultyNPCAdvantage(game);
}

// npc가 not advantage일 때 카드 내려놓기
void npcPutDownCardNotAdvantage(Game *game)
{
   int ranpos;
   ranpos = rand() % 2; //왼쪽,오른쪽 자리 선택
                        // Sleep(game->npc->tmpAvgTimeUserPutDownBell*1000);

   if (ranpos == 0) // NPC오른쪽에 카드 놓기
   {
      putDownCard(game->npc->originCardSet, game->npc->rightCardSet);
      if(game->npc->rightCardSet->root->id == BLOCK){
      return;
   }
      game->who = 0;
      //game->lastTime = game->playTime;
   }
   else if (ranpos == 1) // NPC왼쪽에 카드 놓기
   {
      putDownCard(game->npc->originCardSet, game->npc->leftCardSet);
      if(game->npc->leftCardSet->root->id == BLOCK){
      return;
   }
      game->who = 0;
      //game->lastTime = game->playTime;
   }
}