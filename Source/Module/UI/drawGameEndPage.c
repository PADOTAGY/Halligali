
#include "UI.h"

CoordStr gameEndPageNPCWin[7] = {

    {SCREEN_MID_X - 40, "####    ### #########   ########    ###       ###  ###########  ####    ###"},
    {SCREEN_MID_X - 40, "#####   ### ###    ### ###    ###   ###       ###      ###      #####   ###"},
    {SCREEN_MID_X - 40, "######  ### ###    ### ###          ###       ###      ###      ######  ###"},
    {SCREEN_MID_X - 40, "### ### ### #########  ###          ###  ###  ###      ###      ### ### ###"},
    {SCREEN_MID_X - 40, "###  ###### ###        ###          ### ##### ###      ###      ###  ######"},
    {SCREEN_MID_X - 40, "###   ##### ###        ###    ###    ##### #####       ###      ###   #####"},
    {SCREEN_MID_X - 40, "###    #### ###         ########      ###   ###    ###########  ###    ####"}};

CoordStr gameEndPageUserWin[7] = {
    {SCREEN_MID_X - 40, "###    ###  ########  ########## #########   ###       ### ########### ####    ###"},
    {SCREEN_MID_X - 40, "###    ### ###    ### ###        ###    ###  ###       ###     ###     #####   ###"},
    {SCREEN_MID_X - 40, "###    ### ###        ###        ###    ###  ###       ###     ###     ######  ### "},
    {SCREEN_MID_X - 40, "###    ### ########## ########   #########   ###  ###  ###     ###     ### ### ###"},
    {SCREEN_MID_X - 40, "###    ###        ### ###        ###    ###  ### ##### ###     ###     ###  ######"},
    {SCREEN_MID_X - 40, "###    ### ###    ### ###        ###    ###   ##### #####      ###     ###   #####"},
    {SCREEN_MID_X - 40, " ########   ########  ########## ###    ###    ###   ###   ########### ###    ####"}};


CoordStr gameEndPageKey[7] = {

    {SCREEN_MID_X - 60, "#####   #####   ######   ####    ####      #    #  ######  #   #     #####    ##       #####   ######  #####  #####   #   #"},
    {SCREEN_MID_X - 60, "#    #  #    #  #       #    #  #    #     #   #   #       #   #       #     #  #      #    #  #         #    #    #  #   #"},
    {SCREEN_MID_X - 60, "#    #  #    #  #       #       #          #  #    #       #   #       #    #    #     #    #  #         #    #    #  #   #"},
    {SCREEN_MID_X - 60, "#####   #####   ####     ####    ####      ###     ####     ###        #    #    #     #####   ####      #    #####    ###"},
    {SCREEN_MID_X - 60, "#       #  #    #            #       #     #  #    #         #         #    #    #     #  #    #         #    #  #      #"},
    {SCREEN_MID_X - 60, "#       #   #   #       #    #  #    #     #   #   #         #         #     #  #      #   #   #         #    #   #     #"},
    {SCREEN_MID_X - 60, "#       #    #  ######   ####    ####      #    #  ######    #         #      ##       #    #  ######    #    #    #    #"}};

void drawGameEndPage()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
    // if(npc win)
    for (int line = 0; line < 7; line++)
        printOnPos(gameEndPageNPCWin[line].str, gameEndPageNPCWin[line].posX, SCREEN_MID_Y + line - 20);
    // if(user win)
    //for (int line = 0; line < 7; line++)
    //  printOnPos(gameEndPageUserWin[line].str, gameEndPageUserWin[line].posX, SCREEN_MID_Y + line - 20);

    for (int line = 0; line < 7; line++)
        printOnPos(gameEndPageKey[line].str, gameEndPageKey[line].posX, SCREEN_MID_Y + line - 7);

    getchar();
}
