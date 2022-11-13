
NAME = test.exe

SRCS = 	test.c\
		deleteCard.c\
		drawCard.c\
		drawScrean.c\
		drawHitBellMotion.c\
		initTerminal.c\
		UIutil.c

OBJS = $(SRCS:.c=.o)


all: $(NAME)

$(NAME)	: $(OBJS)
	gcc -o $(NAME) $(OBJS)

%.o : %.c
	gcc -c $^ -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re