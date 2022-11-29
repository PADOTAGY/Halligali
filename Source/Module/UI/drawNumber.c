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
    static int lastUserScore = -1;
    static int lastNpcScore = -1;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
    if (lastNpcScore != game->npc->score)
    {
        if (game->npc->score / 10 == 0)
        {

            printBigNumber(-1, 9, 12);
            printBigNumber(game->npc->score, 9, 12);
        }
        else
        {
            if (lastNpcScore == 9)
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
        lastNpcScore++;
    }
    if (lastUserScore != game->user->score)
    {
        if (game->user->score / 10 == 0)
        {
            printBigNumber(-1, 9, 43);
            printBigNumber(game->user->score, 9, 43);
        }
        else
        {
            if (lastUserScore == 9)
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
        lastUserScore++;
    }
}