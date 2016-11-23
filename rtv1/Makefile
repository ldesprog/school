NAME = rtv1

INC = -I./includes/ -I./libft/ 

SRC =	main.c \
		fonc_vector.c \
		ft_put_pixel.c \
		ft_intersection.c \
		ft_hit.c \
		full_obj.c \
		malloc_obj.c \
		ft_parcing.c

OBJECT = camera.c \
			light.c \
			sphere.c \
			plane.c \
			cylinder.c \
			cone.c

#MATRICE =

#VECTOR = 

SRCS = $(addprefix ./srcs/src/, $(SRC))
SRCS += $(addprefix ./srcs/obj/, $(OBJECT))
#SRCS += $(addprefix ./srcs/vector/, $(VECTOR))
#SRCS += $(addprefix ./srcs/matrice/, $(MATRICE))

OBJ = $(SRCS:.c=.o)

CFLAGS = -Wall -Werror -Wextra $(INC)
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