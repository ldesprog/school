NAME = a.ls

SRC = ft_affichage.c \
		ft_affichage_2.c \
		ft_ls.c \
		ft_ls_error.c \
		ft_ls_gr.c \
		ft_ls_l.c \
		ft_ls_t.c \
		ft_ls_tri.c \
		main.c

CFLAGS = -Wall -Werror -Wextra -I./

LIBFT = libft/libft.a

all: $(LIBFT) $(NAME)

$(NAME):
	gcc $(CFLAGS) $(SRC) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C libft/

clean:
	make -C libft/ clean

fclean: clean
	make -C ./libft/ fclean
	rm -rf $(NAME)

re: fclean all
