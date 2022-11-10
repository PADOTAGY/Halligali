#ifndef UI_H
# define UI_H

# include <stdio.h>
# include <Windows.h>

// UIUtil
void setCurrentCursorPos(int x, int y);
COORD getCurrentCursorPos(void);

void initTerminal(void);

#endif