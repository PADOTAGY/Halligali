
#include "UI.h"

CoordStr gameStartPageName[14] = {
    {SCREEN_MID_X - 40, "##     ##    ###    ##       ##       ####  ######      ###    ##       ##       ####"},
    {SCREEN_MID_X - 40, "##     ##   ## ##   ##       ##        ##  ##    ##    ## ##   ##       ##        ## "},
    {SCREEN_MID_X - 40, "##     ##  ##   ##  ##       ##        ##  ##         ##   ##  ##       ##        ## "},
    {SCREEN_MID_X - 40, "######### ##     ## ##       ##        ##  ##   #### ##     ## ##       ##        ## "},
    {SCREEN_MID_X - 40, "##     ## ######### ##       ##        ##  ##    ##  ######### ##       ##        ## "},
    {SCREEN_MID_X - 40, "##     ## ##     ## ##       ##        ##  ##    ##  ##     ## ##       ##        ## "},
    {SCREEN_MID_X - 40, "##     ## ##     ## ######## ######## ####  ######   ##     ## ######## ######## ####"},
    {SCREEN_MID_X - 20, "#### ##    ##    ########   #######   ######  "},
    {SCREEN_MID_X - 20, " ##  ###   ##    ##     ## ##     ## ##    ## "},
    {SCREEN_MID_X - 20, " ##  ####  ##    ##     ## ##     ## ##       "},
    {SCREEN_MID_X - 20, " ##  ## ## ##    ##     ## ##     ##  ######  "},
    {SCREEN_MID_X - 20, " ##  ##  ####    ##     ## ##     ##       ## "},
    {SCREEN_MID_X - 20, " ##  ##   ###    ##     ## ##     ## ##    ## "},
    {SCREEN_MID_X - 20, "#### ##    ##    ########   #######   ######  "},
};

CoordStr gameStartPageKey[7] = {
    {SCREEN_MID_X - 45, "######                                 #######                               #    #"},
    {SCREEN_MID_X - 45, "#     # #####  ######  ####   ####     #       #    # ##### ###### #####     #   #  ###### #   #"},
    {SCREEN_MID_X - 45, "#     # #    # #      #      #         #       ##   #   #   #      #    #    #  #   #       # #"},
    {SCREEN_MID_X - 45, "######  #    # #####   ####   ####     #####   # #  #   #   #####  #    #    ###    #####    #"},
    {SCREEN_MID_X - 45, "#       #####  #           #      #    #       #  # #   #   #      #####     #  #   #        #"},
    {SCREEN_MID_X - 45, "#       #   #  #      #    # #    #    #       #   ##   #   #      #   #     #   #  #        #"},
    {SCREEN_MID_X - 45, "#       #    # ######  ####   ####     ####### #    #   #   ###### #    #    #    # ######   #"},
};

void drawGameStartPage()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
    for (int line = 0; line < 7; line++)
        printOnPos(gameStartPageName[line].str, gameStartPageName[line].posX, SCREEN_MID_Y + line - 15);

    for (int line = 7; line < 14; line++)
        printOnPos(gameStartPageName[line].str, gameStartPageName[line].posX, SCREEN_MID_Y + line - 15 + 2);

    for (int line = 0; line < 7; line++)
        printOnPos(gameStartPageKey[line].str, gameStartPageKey[line].posX, SCREEN_MID_Y + line + 6);
}
