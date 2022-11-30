
#include "UI.h"

CoordStr bellModel[15] = {
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

void drawBell()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
    for (int line = 0; line < 15; line++)
        printOnPos(bellModel[line].str, bellModel[line].posX, BELL_BASIS_Y + line);
}

void reDrawBell(int flint)
{
    static int count;

    if (flint == 1)
    {
        count = 15;
    }

    if (count <= 0)
    {
        count = 0;
        return;
    }

    drawBell();
    count--;
}