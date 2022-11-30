#include "UI.h"

void static printSmallNumber(int number, int posX, int posY)
{
    switch (number)
    {
    case 1:
        printOnPos("   ##  ", posX, posY);
        printOnPos("  ###  ", posX, posY + 1);
        printOnPos(" # ##  ", posX, posY + 2);
        printOnPos("   ##  ", posX, posY + 3);
        printOnPos("#######", posX, posY + 4);
        break;
    case 2:
        printOnPos(" ##### ", posX, posY);
        printOnPos("##   ##", posX, posY + 1);
        printOnPos("    ## ", posX, posY + 2);
        printOnPos("  ##   ", posX, posY + 3);
        printOnPos("#######", posX, posY + 4);
        break;
    case 3:
        printOnPos("###### ", posX, posY);
        printOnPos("     ##", posX, posY + 1);
        printOnPos("   ### ", posX, posY + 2);
        printOnPos("     ##", posX, posY + 3);
        printOnPos("###### ", posX, posY + 4);
        break;
    case 4:
        printOnPos("##     ", posX, posY);
        printOnPos("##     ", posX, posY + 1);
        printOnPos("## ##  ", posX, posY + 2);
        printOnPos("#######", posX, posY + 3);
        printOnPos("   ##  ", posX, posY + 4);
        break;
    case 5:
        printOnPos("#######", posX, posY);
        printOnPos("##     ", posX, posY + 1);
        printOnPos("###### ", posX, posY + 2);
        printOnPos("     ##", posX, posY + 3);
        printOnPos("###### ", posX, posY + 4);
        break;
    case 6:
        printOnPos("  #####", posX, posY);
        printOnPos(" ##    ", posX, posY + 1);
        printOnPos(" ##### ", posX, posY + 2);
        printOnPos(" ##  ##", posX, posY + 3);
        printOnPos("  #### ", posX, posY + 4);
        break;
    case 7:
        printOnPos("#######", posX, posY);
        printOnPos("##  ## ", posX, posY + 1);
        printOnPos("   ##  ", posX, posY + 2);
        printOnPos("  ##   ", posX, posY + 3);
        printOnPos("  ##   ", posX, posY + 4);
        break;
    case 8:
        printOnPos(" ##### ", posX, posY);
        printOnPos("##   ##", posX, posY + 1);
        printOnPos(" ##### ", posX, posY + 2);
        printOnPos("##   ##", posX, posY + 3);
        printOnPos(" ##### ", posX, posY + 4);
        break;
    case 9:
        printOnPos(" ##### ", posX, posY);
        printOnPos("##   ##", posX, posY + 1);
        printOnPos(" ######", posX, posY + 2);
        printOnPos("     ##", posX, posY + 3);
        printOnPos("###### ", posX, posY + 4);
        break;
    case 0:
        printOnPos(" ##### ", posX, posY);
        printOnPos("##  ###", posX, posY + 1);
        printOnPos("##   ##", posX, posY + 2);
        printOnPos("###  ##", posX, posY + 3);
        printOnPos(" ##### ", posX, posY + 4);
        break;
    case -1:
        printOnPos("       ", posX, posY);
        printOnPos("       ", posX, posY + 1);
        printOnPos("       ", posX, posY + 2);
        printOnPos("       ", posX, posY + 3);
        printOnPos("       ", posX, posY + 4);
        break;
    }
}
void static printBigNumber(int number, int posX, int posY)
{
    switch (number)
    {
    case 1:
        printOnPos("    ###    ", posX, posY);
        printOnPos("  #####    ", posX, posY + 1);
        printOnPos("    ###    ", posX, posY + 2);
        printOnPos("    ###    ", posX, posY + 3);
        printOnPos("    ###    ", posX, posY + 4);
        printOnPos("    ###    ", posX, posY + 5);
        printOnPos("  #######  ", posX, posY + 6);
        break;
    case 2:
        printOnPos(" ########  ", posX, posY);
        printOnPos("###    ### ", posX, posY + 1);
        printOnPos("      ###  ", posX, posY + 2);
        printOnPos("    ###    ", posX, posY + 3);
        printOnPos("  ###      ", posX, posY + 4);
        printOnPos(" ###       ", posX, posY + 5);
        printOnPos("########## ", posX, posY + 6);
        break;
    case 3:
        printOnPos(" ########  ", posX, posY);
        printOnPos("###    ### ", posX, posY + 1);
        printOnPos("       ### ", posX, posY + 2);
        printOnPos("    ####   ", posX, posY + 3);
        printOnPos("       ### ", posX, posY + 4);
        printOnPos("###    ### ", posX, posY + 5);
        printOnPos(" ########  ", posX, posY + 6);
        break;
    case 4:
        printOnPos("    ###    ", posX, posY);
        printOnPos("   ###     ", posX, posY + 1);
        printOnPos("  ### ###  ", posX, posY + 2);
        printOnPos(" ###  ###  ", posX, posY + 3);
        printOnPos("###########", posX, posY + 4);
        printOnPos("      ###  ", posX, posY + 5);
        printOnPos("      ###  ", posX, posY + 6);
        break;
    case 5:
        printOnPos("########## ", posX, posY);
        printOnPos("###    ### ", posX, posY + 1);
        printOnPos("###        ", posX, posY + 2);
        printOnPos("#########  ", posX, posY + 3);
        printOnPos("       ### ", posX, posY + 4);
        printOnPos("###    ### ", posX, posY + 5);
        printOnPos(" ########  ", posX, posY + 6);
        break;
    case 6:
        printOnPos(" ########  ", posX, posY);
        printOnPos("###    ### ", posX, posY + 1);
        printOnPos("###        ", posX, posY + 2);
        printOnPos("#########  ", posX, posY + 3);
        printOnPos("###    ### ", posX, posY + 4);
        printOnPos("###    ### ", posX, posY + 5);
        printOnPos(" ########  ", posX, posY + 6);
        break;
    case 7:
        printOnPos("###########", posX, posY);
        printOnPos("###     ###", posX, posY + 1);
        printOnPos("       ### ", posX, posY + 2);
        printOnPos("      ###  ", posX, posY + 3);
        printOnPos("     ###   ", posX, posY + 4);
        printOnPos("    ###    ", posX, posY + 5);
        printOnPos("    ###    ", posX, posY + 6);
        break;
    case 8:

        printOnPos(" ########  ", posX, posY);
        printOnPos("###    ### ", posX, posY + 1);
        printOnPos("###    ### ", posX, posY + 2);
        printOnPos(" ########  ", posX, posY + 3);
        printOnPos("###    ### ", posX, posY + 4);
        printOnPos("###    ### ", posX, posY + 5);
        printOnPos(" ########  ", posX, posY + 6);
        break;
    case 9:

        printOnPos(" ########  ", posX, posY);
        printOnPos("###    ### ", posX, posY + 1);
        printOnPos("###    ### ", posX, posY + 2);
        printOnPos(" ######### ", posX, posY + 3);
        printOnPos("       ### ", posX, posY + 4);
        printOnPos("###    ### ", posX, posY + 5);
        printOnPos(" ########  ", posX, posY + 6);
        break;
    case 0:
        printOnPos("  #######  ", posX, posY);
        printOnPos(" ###   ### ", posX, posY + 1);
        printOnPos(" ###  #### ", posX, posY + 2);
        printOnPos(" ### # ### ", posX, posY + 3);
        printOnPos(" ####  ### ", posX, posY + 4);
        printOnPos(" ###   ### ", posX, posY + 5);
        printOnPos("  #######  ", posX, posY + 6);
        break;
    case -1:
        printOnPos("           ", posX, posY);
        printOnPos("           ", posX, posY + 1);
        printOnPos("           ", posX, posY + 2);
        printOnPos("           ", posX, posY + 3);
        printOnPos("           ", posX, posY + 4);
        printOnPos("           ", posX, posY + 5);
        printOnPos("           ", posX, posY + 6);
        break;
    }
}
void static printPlus(int posX, int posY)
{
    printOnPos(" # ", posX, posY);
    printOnPos("###", posX, posY + 1);
    printOnPos(" # ", posX, posY + 2);
}
void updateScore(Game *game)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
    if (game->npc->score / 10 == 0)
    {

        printBigNumber(-1, 9, 12);
        printBigNumber(game->npc->score, 9, 12);
    }
    else
    {
        if (game->npc->score == 9)
        {
            printBigNumber(-1, 9, 12);
        }
        if (game->npc->score / 10 > 1)
        {
            printPlus(25, 10);
        }
        else
        {
            printBigNumber(-1, 3, 12);
            printBigNumber(-1, 16, 12);
            printBigNumber(game->npc->score / 10, 3, 12);
            printBigNumber(game->npc->score % 10, 16, 12);
        }
    }
    if (game->user->score / 10 == 0)
    {
        printBigNumber(-1, 9, 43);
        printBigNumber(game->user->score, 9, 43);
    }
    else
    {
        if (game->user->score == 9)
        {
            printBigNumber(-1, 9, 43);
        }
        if (game->user->score / 10 > 1)
        {
            printPlus(25, 41);
        }
        else
        {
            printBigNumber(-1, 3, 43);
            printBigNumber(-1, 16, 43);
            printBigNumber(game->user->score / 10, 3, 43);
            printBigNumber(game->user->score % 10, 16, 43);
        }
    }
}
void updateCardSetNumber(Game *game)
{
    static int lastUserCardSetNumber;
    static int lastNpcCardSetNumber;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
    if (lastNpcCardSetNumber != game->npc->originCardSet->count)
    {
        if (game->npc->originCardSet->count / 10 == 0)
        {
            if (lastNpcCardSetNumber > 9)
            {
                printSmallNumber(-1, SCREEN_MID_X - 7, SCREEN_MID_Y - SCREEN_MID_Y / 2 - 2);
                printSmallNumber(-1, SCREEN_MID_X + 1, SCREEN_MID_Y - SCREEN_MID_Y / 2 - 2);
            }
            printSmallNumber(-1, SCREEN_MID_X - 3, SCREEN_MID_Y - SCREEN_MID_Y / 2 - 2);
        }
        else
        {
            if (lastNpcCardSetNumber < 10)
            {
                printSmallNumber(-1, SCREEN_MID_X - 3, SCREEN_MID_Y - SCREEN_MID_Y / 2 - 2);
            }

            printSmallNumber(-1, SCREEN_MID_X - 7, SCREEN_MID_Y - SCREEN_MID_Y / 2 - 2);
            printSmallNumber(-1, SCREEN_MID_X + 1, SCREEN_MID_Y - SCREEN_MID_Y / 2 - 2);
        }
        lastNpcCardSetNumber = game->npc->originCardSet->count;
    }
    if (game->npc->originCardSet->count / 10 == 0)
    {
        printSmallNumber(game->npc->originCardSet->count, SCREEN_MID_X - 3, SCREEN_MID_Y - SCREEN_MID_Y / 2 - 2);
    }
    else
    {
        printSmallNumber(game->npc->originCardSet->count / 10, SCREEN_MID_X - 7, SCREEN_MID_Y - SCREEN_MID_Y / 2 - 2);
        printSmallNumber(game->npc->originCardSet->count % 10, SCREEN_MID_X + 1, SCREEN_MID_Y - SCREEN_MID_Y / 2 - 2);
    }
    if (lastUserCardSetNumber != game->user->originCardSet->count)
    {
        if (game->user->originCardSet->count / 10 == 0)
        {
            if (lastUserCardSetNumber > 9)
            {
                printSmallNumber(-1, SCREEN_MID_X - 7, SCREEN_MID_Y + SCREEN_MID_Y / 2 - 2);
                printSmallNumber(-1, SCREEN_MID_X + 1, SCREEN_MID_Y + SCREEN_MID_Y / 2 - 2);
            }
            printSmallNumber(-1, SCREEN_MID_X - 3, SCREEN_MID_Y + SCREEN_MID_Y / 2 - 2);
        }
        else
        {
            if (lastUserCardSetNumber < 10)
            {
                printSmallNumber(-1, SCREEN_MID_X - 3, SCREEN_MID_Y + SCREEN_MID_Y / 2 - 2);
            }

            printSmallNumber(-1, SCREEN_MID_X - 7, SCREEN_MID_Y + SCREEN_MID_Y / 2 - 2);
            printSmallNumber(-1, SCREEN_MID_X + 1, SCREEN_MID_Y + SCREEN_MID_Y / 2 - 2);
        }
        lastUserCardSetNumber = game->user->originCardSet->count;
    }
    if (game->user->originCardSet->count / 10 == 0)
    {
        printSmallNumber(game->user->originCardSet->count, SCREEN_MID_X - 3, SCREEN_MID_Y + SCREEN_MID_Y / 2 - 2);
    }
    else
    {
        printSmallNumber(game->user->originCardSet->count / 10, SCREEN_MID_X - 7, SCREEN_MID_Y + SCREEN_MID_Y / 2 - 2);
        printSmallNumber(game->user->originCardSet->count % 10, SCREEN_MID_X + 1, SCREEN_MID_Y + SCREEN_MID_Y / 2 - 2);
    }
}