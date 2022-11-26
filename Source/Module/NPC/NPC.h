#ifndef NPC_H
#define NPC_H
#include "../Reusable/Reusable.h"

//함수 선언
//npc 카드 내려 놓기
int checkIsNPCAdvantage(Game *game);
void npcPutDownCard(Game *game);
void npcPutDownCardNotAdvantage(Game *game);
void npcPutDownCardAdvantage(Game *game);
double getTimeWhenNPCDrawCard(void);
//npc 난이도 조절
void raiseDifficultyNPCAdvantage(NPC *npc);
void returnRaiseDifficultyNPCAdvantage(NPC *npc);
//user가 종치는 시간관련
void calcAverageTimeUserPutDownBell(Game *game, NPC *npc);
double getTimeUserPutDownBell(Game *game);
//npc 종치기
void npcPutDownBell(Game *game,NPC *npc);
void missPutDownBell(Game *game, NPC *npc);
int isMissPutDownBell(Game *game, NPC *npc);

#endif

//시작화면 만들기 미완성
// CoordStr gameStartPageName[14] = {
// 	{ SCREEN_MID_X - 40, "##     ##    ###    ##       ##       ####  ######      ###    ##       ##       ####" },
// 	{ SCREEN_MID_X - 40, "##     ##   ## ##   ##       ##        ##  ##    ##    ## ##   ##       ##        ## " },
// 	{ SCREEN_MID_X - 40, "##     ##  ##   ##  ##       ##        ##  ##         ##   ##  ##       ##        ## " },
// 	{ SCREEN_MID_X - 40, "######### ##     ## ##       ##        ##  ##   #### ##     ## ##       ##        ## " },
// 	{ SCREEN_MID_X - 40, "##     ## ######### ##       ##        ##  ##    ##  ######### ##       ##        ## " },
// 	{ SCREEN_MID_X - 40, "##     ## ##     ## ##       ##        ##  ##    ##  ##     ## ##       ##        ## " },
// 	{ SCREEN_MID_X - 40, "##     ## ##     ## ######## ######## ####  ######   ##     ## ######## ######## ####" },
// 	{ SCREEN_MID_X - 20, "#### ##    ##    ########   #######   ######  " },
// 	{ SCREEN_MID_X - 20, " ##  ###   ##    ##     ## ##     ## ##    ## " },
// 	{ SCREEN_MID_X - 20, " ##  ####  ##    ##     ## ##     ## ##       " },
// 	{ SCREEN_MID_X - 20, " ##  ## ## ##    ##     ## ##     ##  ######  " },
// 	{ SCREEN_MID_X - 20, " ##  ##  ####    ##     ## ##     ##       ## " },
// 	{ SCREEN_MID_X - 20, " ##  ##   ###    ##     ## ##     ## ##    ## " },
// 	{ SCREEN_MID_X - 20, "#### ##    ##    ########   #######   ######  " },
// };

// CoordStr gameStartPageKey[7] = {
// 	{ SCREEN_MID_X - 45, "######                                 #######                               #    #" },
// 	{ SCREEN_MID_X - 45, "#     # #####  ######  ####   ####     #       #    # ##### ###### #####     #   #  ###### #   #" },
// 	{ SCREEN_MID_X - 45, "#     # #    # #      #      #         #       ##   #   #   #      #    #    #  #   #       # #" },
// 	{ SCREEN_MID_X - 45, "######  #    # #####   ####   ####     #####   # #  #   #   #####  #    #    ###    #####    #" },
// 	{ SCREEN_MID_X - 45, "#       #####  #           #      #    #       #  # #   #   #      #####     #  #   #        #" },
// 	{ SCREEN_MID_X - 45, "#       #   #  #      #    # #    #    #       #   ##   #   #      #   #     #   #  #        #" },
// 	{ SCREEN_MID_X - 45, "#       #    # ######  ####   ####     ####### #    #   #   ###### #    #    #    # ######   #" },
// };

// void drawGameStartPage()
// {
// 	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
// 	for (int line = 0; line < 7; line++)
// 		printOnPos(gameStartPageName[line].str, gameStartPageName[line].posX, SCREEN_MID_Y + line-15);
	
// 	for (int line = 7; line < 14; line++)
// 		printOnPos(gameStartPageName[line].str, gameStartPageName[line].posX, SCREEN_MID_Y + line-15+2);

// 	for (int line = 0; line < 7; line++)
// 		printOnPos(gameStartPageKey[line].str, gameStartPageKey[line].posX, SCREEN_MID_Y+line+6);
	
// 	//enter키 입력하면 콘솔창 다 지우고 다음 코드 실행
// }