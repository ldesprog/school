NAME = fractol

CFLAGS = -Wall -Wextra -Werror -I./

LFLAGS = -lmlx -framework OpenGL -framework AppKit

SRC =	main.c \
		ft_calc.c \
		ft_event.c \
		ft_fractale.c \
		ft_paint.c

OBJ = $(SRC:.c=.o)

LIBFT = libft/libft.a

all: $(LIBFT) $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(CFLAGS) $(LFLAGS) $(LIBFT) $(OBJ) 

$(LIBFT):
	make -C libft/

clean:
	rm -f $(OBJ)
	make -C libft/ clean

fclean: clean
	make -C ./libft/ fclean
	rm -f $(NAME)

re: fclean all