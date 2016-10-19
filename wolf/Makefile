NAME = wolf3d

SRC = ft_calc_ray.c \
		ft_fonc.c \
		ft_fonc_2.c \
		ft_event.c \
		ft_paint.c \
		raycast.c \
		get_next_line.c \
		wolf.c \
		ft_hud.c \
		ft_hud_2.c \
		ft_print_key.c \
		ft_print_key_2.c \
		ft_action.c \
		ft_map.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra -I./
#LFLAGS = -L/usr/X11/lib -lmlx -lXext -lX11
LFLAGS = -lmlx -framework OpenGL -framework AppKit

LIBFT = libft/libft.a

all: $(LIBFT) $(NAME)

$(NAME): $(OBJ)
	gcc $(CFLAGS) $(LFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C libft/

clean:
	rm -f $(OBJ)
	make -C libft/ clean

fclean: clean
	make -C ./libft/ fclean
	rm -rf $(NAME)

re: fclean all