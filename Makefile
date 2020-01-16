NAME	= my_sokoban

CC	= gcc

RM	= rm -f

SRCS	=	src/main.c			\
		src/button.c			\
		src/number_of_holes_and_boxes.c	\
		src/win_and_loose_condition.c	\
		src/error.c			\
		src/pad.c			\
		src/create_two_map.c		\
		src/get_map.c

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I
CFLAGS += -Wall -Wextra -g3

all: $(NAME)

$(NAME): $(OBJS)
	 make re -C lib/my
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS) -L./lib -lmy -lncurses

clean:
	$(RM) $(OBJS)
	$(RM) lib/libmy.a

fclean: clean
	$(RM) $(NAME)
	cd lib/my/; make fclean
re: fclean all

.PHONY: all clean fclean re
