NAME = wolf3d

SRC = ft_calc_ray.c \
		ft_fonc.c \
		ft_event.c \
		ft_paint.c \
		raycast.c \
		get_next_line.c \
		wolf.c

CFLAGS = -Wall -Werror -Wextra -I./
#LFLAGS = -L/usr/X11/lib -lmlx -lXext -lX11
LFLAGS = -lmlx -framework OpenGL -framework AppKit

LIBFT = libft/libft.a

all: $(LIBFT) $(NAME)

$(NAME):
	gcc $(CFLAGS) $(LFLAGS) $(SRC) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C libft/

clean:
	make -C libft/ clean

fclean: clean
	make -C ./libft/ fclean
	rm -rf $(NAME)

re: fclean all