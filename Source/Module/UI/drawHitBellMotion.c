
#include "UI.h"

CoordStr handModel[39] = {
    {20, "d8 8b", "     "},
    {19, "8I    b", "       "},
    {11, ",ad8b, d      8", "               "},
    {10, "d     b 8,     q ,8 88,", "                       "},
    {10, "8I     dP      dP    I8", "                       "},
    {10, "8      d8      8      8I", "                        "},
    {9, "I8      Ib      ,8     8I", "                         "},
    {5, "dPb 8       8,      IP     8I", "                             "},
    {4, "8    qI      8,      q8     8b", "                              "},
    {4, "8    Yb      8,      8I     8b", "                              "},
    {3, "d      8      b,      q8     8b", "                               "},
    {3, "I8     8      b       f8      8", "                               "},
    {3, "8,     8,     8       8I      8", "                               "},
    {2, ",8      8      Y       ,8      I8", "                                 "},
    {2, "Ib      8      Y       d8      8I         _,ada,", "                                                "},
    {2, "88      I              8P       8       ,aP    Yb", "                                                 "},
    {2, "Ib      ,                        8     aP      Yb", "                                                 "},
    {1, ",I                                I8   ,P       Yb", "                                                  "},
    {1, "8                                   8  P       ,aP", "                                                  "},
    {1, "I                                   YP         ,aP", "                                                  "},
    {0, ",8                                    8        ,aP", "                                                  "},
    {0, "I8                                            ,aP", "                                                 "},
    {1, "8,                                           ,dP", "                                                "},
    {0, "8I                                           ,8P", "                                                "},
    {0, "8b                                           8P", "                                               "},
    {0, "I8                                          P", "                                             "},
    {1, "8,                                       ,dP", "                                            "},
    {1, "8I                                      a8P", "                                           "},
    {2, "8,                                   ,d8P", "                                         "},
    {3, "8,                               ,adP", "                                     "},
    {4, "8,                            ,adP", "                                  "},
    {4, "8I                           ,adP", "                                 "},
    {4, "I8                          ,dP", "                               "},
    {4, "8I                         ,8P", "                              "},
    {4, "8P                        ,dP", "                             "},
    {3, ",8                        ,8P", "                             "},
    {3, "dI                       ,8P", "                            "},
    {2, ",8                       ,8P", "                            "},
    {2, "IP                      ,8P", "                           "}};

static void drawHand(int posX, int posY)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    for (int line = 0; line < 39; line++)
    {
        if (posY + line >= 63)
            break;
        printOnPos(handModel[line].str, posX + handModel[line].posX, posY + line);
    }
}

static void deleteHand(int posX, int posY)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
    for (int line = 0; line < 39; line++)
    {
        if (posY + line >= 63)
            break;
        printOnPos(handModel[line].blank, posX + handModel[line].posX, posY + line);
    }
}

void drawHitBellMotion(int flint)
{
    static int beforePosY; // ?????? ?????? ??? ??????
    static int newPosY;    // ?????? ????????? ??? ??????
    static int dy;         // ??????

    if (flint == 1)
    {
        dy = -5;
        PlaySound(TEXT(BELL_SOUND), NULL, SND_ASYNC);
    }

    if (dy == 0) // ??????
    {
        beforePosY = 63;
        newPosY = 63;
        return;
    }

    // ?????? ??? ?????????
    deleteHand(HAND_BASIS_X, beforePosY);

    // if (PosY < ?????? ??????) // ?????? ???????????? ?????? ????????? ??????????????? (?????? ????????????  == PosY??? ????????????)
    if (newPosY < SCREEN_MID_Y - 3 + 2)
        dy = 3;

    newPosY = beforePosY + dy;

    // if (PosY <= max_height) // ?????? ??????????????? dy = 0 ?????? ?????? ????????? ?????? ?????????????????? ?????? ???????????? ??????
    if (newPosY >= 63)
        dy = 0;

    // ????????? ??? ?????????
    drawHand(HAND_BASIS_X, newPosY);
    // printf("beforePos = %d newPos = %d\n",beforePosY, newPosY);
    beforePosY = newPosY;
}