/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesprog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/17 15:07:57 by ldesprog          #+#    #+#             */
/*   Updated: 2016/08/17 15:07:58 by ldesprog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "get_next_line.h"
# include <mlx.h>

# define TOURNE 4
# define AVANCE 3

/*
** KEY
*/
# define ECHAP 53
# define TILDE 50
# define EXCLAMATION 18
# define ARROBAZE 19
# define ACHTAGE 20
# define DOLLAR 21
# define MODULO 23
# define CIRCOFLEXE 22
# define ET 26
# define ETOILE 28
# define PARENTHESE_O 25
# define PARENTHESE_F 29
# define UNDESCOR 27
# define PLUS 24
# define DELETE_1 51
# define TAB 48
# define KEY_Q 12
# define KEY_W 13
# define KEY_E 14
# define KEY_R 15
# define KEY_T 17
# define KEY_Y 16
# define KEY_U 32
# define KEY_I 34
# define KEY_O 31
# define KEY_P 35
# define CROCHET_O 33
# define CROCHET_F 30
# define ANTISLASH 42

/*
** COMPORTEMENT ETRANGE SUR CAPS
*/
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_F 3
# define KEY_G 5
# define KEY_H 4
# define KEY_J 38
# define KEY_K 40
# define KEY_L 37
# define POINT_V 41
# define APOSTROPHE 39
# define RETURN 36
# define SHIFT_G 257
# define KEY_Z 6
# define KEY_X 7
# define KEY_C 8
# define KEY_V 9
# define KEY_B 11
# define KEY_N 45
# define KEY_M 46
# define VIRGULE 43
# define POINT 47
# define SLACH 44
# define SHIFT_D 258
# define CONTROL_G 256
# define ALT_G 261
# define COMMAND_G 259
# define ESPACE 49
# define COMMAND_D 260
# define ALT_D 262
# define CONTROL_D 269
# define FN 279
# define HOME 115
# define PAGE_UP 116
# define DELETE_2 117
# define END 119
# define PAGE_DOWN 121
# define PAD_CLEAR 71
# define PAD_EGAL 81
# define PAD_SLACH 75
# define PAD_ETOILE 67
# define PAD_7 89
# define PAD_8 91
# define PAD_9 92
# define PAD_TIRET 78
# define PAD_4 86
# define PAD_5 87
# define PAD_6 88
# define PAD_PLUS 69
# define PAD_1 83
# define PAD_2 84
# define PAD_3 85
# define PAD_0 82
# define PAD_POINT 65
# define PAD_ENTER 76
# define LEFT 123
# define RIGHT 124
# define DOWN 125
# define UP 126

typedef struct	s_pos
{
	float		x;
	float		y;
}				t_pos;

typedef struct	s_player
{
	t_pos		*pos;
	float		dir;
}				t_player;

typedef struct	s_key
{
	int			key_quit;
	int			key_menu;
	int			key_menu_v;
	int			key_enter;
	int			key_enter_v;
	int			key_enter_c;
	int			key_up;
	int			key_up_v;
	int			key_down;
	int			key_down_v;
	int			key_left;
	int			key_left_v;
	int			key_right;
	int			key_right_v;
	int			key_action;
	int			key_action_v;
	int			new_key;
	int			add_new_key;
	int			time_menu;
	int			pos_curseur;
	int			used;
	int			bad_key;
}				t_key;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	int			s_line;
	int			bpp;
	int			*data;
	int			endian;
	int			**map;
	int			map_hight;
	int			map_weight;
	t_player	*player;
	int			hight;
	int			weight;
	int			angle;
	int			dist_ecran;
	int			size;
	int			mur;
	int			plafond;
	float		a;
	float		b;
	int			c;
	float		dir_x;
	float		dir_p;
	int			x;
	int			y;
	int			nb_case_a;
	int			nb_case_b;
	t_key		*key;
	int			ac;
	int			end;
	int			nb;
	char		**av;
}				t_env;

/*
** ft_wolf
*/
void			ft_init_map(t_env *e, char *file);
void			ft_init_env(t_env *env);
int				ft_pos_player(int **map, int len, int high, t_env *e);
int				ft_verif_map(int **map, int len, int high, t_env *e);
int				main(int ac, char **av);

/*
** ft_raycast
*/
void			ft_avance(int i, t_env *e);
void			ft_tourne(int i, t_env *e);
void			ft_raycast_2(t_env *e, int x, float dir_x, float dir);
void			ft_raycast_1(t_env *e, int x, float dir_p, float dir_x);
void			ft_raycast(t_env *e);

/*
** ft_print_key
*/
char			*ft_print_key_error(t_env *e, int *i, int ligne);
char			*ft_print_key_8(int key, t_env *e, int *i, int ligne);
char			*ft_print_key_7(int key, t_env *e, int *i, int ligne);
char			*ft_print_key_6(int key, t_env *e, int *i, int ligne);
char			*ft_print_key_5(int key, t_env *e, int *i, int ligne);
char			*ft_print_key_4(int key, t_env *e, int *i, int ligne);
char			*ft_print_key_3(int key, t_env *e, int *i, int ligne);
char			*ft_print_key_2(int key, t_env *e, int *i, int ligne);
char			*ft_print_key(int key, t_env *e, int *i, int ligne);

/*
** ft_paint
*/
void			ft_color(int c, int *color, t_env *e, int wall);
void			ft_paint(t_env e, int color);
void			ft_ray(t_env *e, int wall, int x, int color);

/*
** ft_map
*/
void			ft_error_map(t_env *e, int error);
void			ft_free_map(t_env *e);
void			ft_multi_map(t_env *e, int ac, char **av);

/*
** ft_hud
*/
int				ft_col_str(t_env *e, int ligne, int mode);
void			ft_texte(t_env *e);
void			ft_texte_2(t_env *e);
void			ft_event_hud(t_key *key);
int				ft_check_key(t_env *e);
void			ft_valide_key(t_env *e);
void			ft_curseur(t_env *e);
void			ft_cadre(t_env *e);
void			ft_menu_2(t_env *e);
void			ft_menu(t_env *e);

/*
** ft_fonc
*/
int				ft_len_str(char *str);
void			ft_init_key(t_env *env);
int				ft_red_cross(t_env *e);
float			ft_abs(float n);
char			**ft_remalloc_tab(char **tab, int n);
int				ft_split_2(int *n, int i, char *str);
int				*ft_split(char *str, int j, int *n);
int				**ft_split_to_int(char **tab, int i, int *j, t_env *e);
void			ft_init_key_v(t_env *e);

/*
** ft_event
*/
void			ft_key_down_2(int keycode, t_env *e);
int				ft_key_down(int keycode, t_env *e);
int				ft_key_up(int keycode, t_env *e);
int				ft_wolf(t_env *e);
void			ft_free(t_env *env);

/*
** ft_calc_ray
*/
void			ft_init_pos(t_pos *pos, float x, float y);
void			ft_init_wall_hori(t_env *e, float dir, t_pos *a, t_pos *t);
float			ft_wall_hori(t_env *e, float dir);
void			ft_init_wall_verti(t_env *e, float dir, t_pos *b, t_pos *t);
float			ft_wall_verti(t_env *e, float dir);

/*
** ft_action
*/
void			ft_change_map(t_env *e);
void			ft_destroy_case(t_env *e, int mode);
void			ft_action_3(t_env *e, float dist, int nb_case, int mode);
void			ft_action_2(t_env *e);
void			ft_action(t_env *e);

#endif
