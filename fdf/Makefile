# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldesprog <ldesprog@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/05 22:11:18 by ldesprog          #+#    #+#              #
#    Updated: 2015/01/05 22:11:19 by ldesprog         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = fdf.c \
		ft_func.c \
		ft_ligne.c \
		ft_main.c \
		ft_strsplit_fdf.c \
		get_next_line/get_next_line.c

CFLAGS = -Wall -Werror -Wextra -I./
LFLAGS = -L/usr/X11/lib -lmlx -lXext -lX11

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
