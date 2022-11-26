
#include "UI.h"

CoordStr handModelNPC[39] = {
    {30, "■■■■■■■■■■", "                    "},
    {30, "■■■■■■■■■■", "                    "},
    {30, "■■■■■■■■■■", "                    "},
    {30, "■■■■■■■■■■", "                    "},
    {30, "■■■■■■■■■■", "                    "},
    {30, "■■■■■■■■■■", "                    "},
    {30, "■■■■■■■■■■", "                    "},
    {30, "■■■■■■■■■■", "                    "},
    {30, "■■■■■■■■■■", "                    "},
    {30, "■■■■■■■■■■", "                    "},
    {30, "■■■■■■■■■■", "                    "},
    {30, "■■■■■■■■■■", "                    "},
    {30, "■■■■■■■■■■", "                    "},
    {30, "■■■■■■■■■■", "                    "},
    {30, "■■■■■■■■■■", "                    "},
    {30, "■■■■■■■■■■", "                    "},
    {30, "■■■■■■■■■■", "                    "},
    {30, "■■■■■■■■■■", "                    "},
    {30, "■■■■■■■■■■", "                    "},
    {30, "■■■■■■■■■■", "                    "},
    {30, "■■■■■■■■■■", "                    "},
    {30, "■■■■■■■■■■", "                    "},
    {30, "■■■■■■■■■■", "                    "},
    {30, "■■■■■■■■■■", "                    "},
    {30, "■■■■■■■■■■", "                    "},
    {30, "■■■■■■■■■■", "                    "},
    {30, "■■■■■■■■■■", "                    "},
    {30, "■■■■■■■■■■", "                    "},
    {30, "■■■■■■■■■■", "                    "},
    {30, "■■■■■■■■■■", "                    "},
    {30, "■■■■■■■■■■", "                    "},
    {30, "■■■■■■■■■■", "                    "},
    {30, "■■■■■■■■■■", "                    "},
    {30, "■■■■■■■■■■", "                    "},
    {30, "■■■■■■■■■■", "                    "},
    {30, "■■■■■■■■■■", "                    "},
    {30, "■■■■■■■■■■", "                    "},
    {30, "■■■■■■■■■■", "                    "},
    {30, "■■■■■■■■■■", "                    "},
};

CoordStr bellModelNPC[15] = {
    {BELL_BASIS_X, ".,.,./&&&&&&&&''..."},
    {BELL_BASIS_X - 5, ".,, ,,...&&&&&&&&&&&&,.....,"},
    {BELL_BASIS_X - 7, ",,,.., . *&&&&&&&&&&&&&&.,...,.,."},
    {BELL_BASIS_X - 8, ",.,.,,, .   &&&&&&&&&&&&    ..,,.,,"},
    {BELL_BASIS_X - 9, ",  ....,,     '&&&&&&&&/       .....,"},
    {BELL_BASIS_X - 9, ".                                ..,,"},
    {BELL_BASIS_X - 10, ",.             .         .    .....,,.."},
    {BELL_BASIS_X - 11, " #,              ............,,.,,.....#."},
    {BELL_BASIS_X - 11, ".##..        ..............,,,,.......(#*"},
    {BELL_BASIS_X - 10, "##&/,..        ..................,,,&&#/"},
    {BELL_BASIS_X - 10, "(#&&(&(**,,..            ...,,**,&#&&&&"},
    {BELL_BASIS_X - 9, ".&&&&&##&&&(//************/#&#&&&&&&&"},
    {BELL_BASIS_X - 6, "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&/"},
    {BELL_BASIS_X - 3, "*&&&&&&&&&&&&&&&&&&&&&&&&/"},
    {BELL_BASIS_X + 1, "'&&&&&&&&&&&&&&&&&/"}};

static void drawHandNPC(int posX, int posY)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    for (int line = 0; line <= posY; line++)
    {
        printOnPos(handModelNPC[line].str, posX + handModelNPC[line].posX, line);
    }
}

static void deleteHandNPC(int posX, int posY)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
    for (int line = 0; line <= posY; line++)
    {
        printOnPos(handModelNPC[line].str, posX + handModelNPC[line].posX, line);
    }
}

void drawHitBellMotionNPC(int flint)
{
    static int beforePosY; // 기존 지울 손 위치
    static int newPosY;    // 새로 출력할 손 위치
    static int dy;         // 변위

    if (flint == 1)
        dy = 4;

    if (dy == 0) // 리턴
    {
        beforePosY = 0;
        newPosY = 0;
        return;
    }

    // 기존 손 지우기
    deleteHandNPC(HAND_BASIS_X, beforePosY);

    // if (PosY < 벨의 위치) // 손이 올라가서 벨을 쳤으면 돌아와야함 (손이 올라간다  == PosY가 줄어든다)
    if (newPosY > SCREEN_MID_Y - 3)
        dy = -3;

    newPosY = beforePosY + dy;

    // if (PosY <= max_height) // 손이 바닥이라면 dy = 0 으로 바꿔 함수가 다시 호출되더라도 손이 그려지지 않음
    if (newPosY < 0)
        dy = 0;

    if (beforePosY > 10)
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
    for (int line = 0; line < 15; line++)
        printOnPos(bellModelNPC[line].str, bellModelNPC[line].posX, line + BELL_BASIS_Y);

    // 새로운 손 그리기
    drawHandNPC(HAND_BASIS_X, newPosY);
    // printf("beforePos = %d newPos = %d\n",beforePosY, newPosY);
    beforePosY = newPosY;
}