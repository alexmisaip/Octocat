CC		=	gcc

NAME		=	Octocat

SRC		=	main.c \
			func.c \
			move.c \
			func2.c \
			menu.c \
			move2.c \
			create.c \
			dir.c

CFLAGS		=	-W -Werror -Wextra -Wall

LDFLAGS		=	-l/libmy

RM		=	rm -f

$(NAME):
		$(CC) $(CFLAGS) $(SRC) -L. $(LDFLAGS) -o $(NAME)

clean:
		$(RM) $(NAME)

re:
		$(RM) $(NAME)
		$(CC) $(CFLAGS) $(SRC) -L. $(LDFLAGS) -o $(NAME)
run:
		$(RM) $(NAME)
		$(CC) $(CFLAGS) $(SRC) -L. $(LDFLAGS) -o $(NAME)
		./$(NAME)