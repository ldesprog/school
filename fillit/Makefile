NAME = fillit

SRC = main.c \
		solve.c \
		ft_fonc.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	gcc $(CFLAGS) $(SRC) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
