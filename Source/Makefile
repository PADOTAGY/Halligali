

NAME = test.exe

SRCS = 	main.c \
		Module\Card\putDownCard.c\
		Module\Card\readyGameboard.c\
		Module\Card\putDownBELL.c\
		Module\Card\cardHandler.c\
		Module\Game\Utils\checkAndRunEndGame.c\
		Module\Game\initGame.c\
		Module\Item\Utils\getNextItem.c\
		Module\Item\Utils\isActiveItem.c\
		Module\Item\Utils\runItem.c\
		Module\Item\runItemModule.c\
		Module\UI\deleteCard.c\
		Module\UI\drawCard.c\
		Module\UI\drawHitBellMotion.c\
		Module\UI\drawScrean.c\
		Module\UI\initTerminal.c\
		Module\UI\UIutil.c\
		Module\UI\updateUI.c\
		Module\NPC\calcAverageTimeUserPutDownBell.c\
		Module\NPC\choosePositionWhenNPCDrawCard.c\
		Module\NPC\getTimeUserPutDownBell.c\
		Module\NPC\getTimeWhenNPCDrawCard.c\
		Module\NPC\npcDifficultyControl.c\
		Module\NPC\npcDrawCard.c\
		Module\NPC\npcHandler.c\
		Module\NPC\npcPutDownBell.c\
		Module\NPC\raiseDifficultyWhenNPCChooseAdvantagePosition.c\
		Module\NPC\checkIsNPCAdvantage.c\

OBJS = $(SRCS:.c=.o)

WINMM = C:\Windows\System32\winmm.dll


all: $(NAME)

$(NAME)	: $(OBJS)
	gcc -o $(NAME) $(OBJS) $(WINMM)

%.o : %.c
	gcc -c $^ -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
