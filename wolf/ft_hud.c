#include "wolf.h"

void	ft_curseur(t_env *e)
{
	int x;
	int y;
	int i;

	x = e->weight / 2;
	y = e->hight / 2;
	i = -10;
	while (i <= 10)
	{
		*(e->data + y * e->s_line / 4 + (x + i)) = 0x555555;
		i++;
	}
	i = -10;
	while (i <= 10)
	{
		*(e->data + (y + i) * e->s_line / 4 + x) = 0x555555;
		i++;
	}
}

/*
** touche utiliser :
** - echap
** - avancer
** - reculer
** - tourner a droite
** - tourner a gauche
** - menu
** - selection
*/

/*
** couleur :
** - blanc de base
** - bleu si curseur
** - vert si selectionner
** - rouge si changer et selectionner
*/

/*
** appuyer sur entrer pour selection
** idem pour valider le changement
*/

void	ft_cadre(t_env *e)
{
	int x;
	int y;

	x = 20;
	while (x <= 530)
	{
		y = 20;
		while (y <= 25)
		{
			*(e->data + y * e->s_line / 4 + x) = 0x888888;
			y++;
		}
		x++;
	}
	x = 20;
	while (x <= 25)
	{
		y = 20;
		while (y <= 220)
		{
			*(e->data + y * e->s_line / 4 + x) = 0x888888;
			y++;
		}
		x++;
	}
	x = 20;
	while (x <= 530)
	{
		y = 215;
		while (y <= 220)
		{
			*(e->data + y * e->s_line / 4 + x) = 0x888888;
			y++;
		}
		x++;
	}
	x = 525;
	while (x <= 530)
	{
		y = 20;
		while (y <= 220)
		{
			*(e->data + y * e->s_line / 4 + x) = 0x888888;
			y++;
		}
		x++;
	}
	x = 26;
	while (x < 525)
	{
		y = 26;
		while (y < 215)
		{
			*(e->data + y * e->s_line / 4 + x) = 0x000000;
			y++;
		}
		x++;
	}
}

int		ft_color_string(t_env *e, int ligne, int mode)
{
	if (mode == 2)
	{
		if (e->key->add_new_key == 1 && ligne == e->key->pos_curseur)
			return (0x00aa00);
		if (e->key->add_new_key == 2 && ligne == e->key->pos_curseur)
			return (0xaa0000);
		if (ligne == e->key->pos_curseur && ligne == e->key->pos_curseur)
			return (0x0000ff);
	}
	else if (ligne == e->key->pos_curseur)
		return (0x0000ff);
	return (0xffffff);
}

void	ft_texte(t_env *e)
{
	int nb;

	nb = 1;
	mlx_string_put(e->mlx, e->win, 150, 35, 0xffffff, "Menu d'option wolf3D" );
	mlx_string_put(e->mlx, e->win, 30, 65, ft_color_string(e, 0, 1), "quitter : ");
	mlx_string_put(e->mlx, e->win, 30, 85, ft_color_string(e, 1, 1), "menu : ");
	mlx_string_put(e->mlx, e->win, 30, 105, ft_color_string(e, 2, 1), "valider : ");
	mlx_string_put(e->mlx, e->win, 30, 125, ft_color_string(e, 3, 1), "avancer : ");
	mlx_string_put(e->mlx, e->win, 30, 145, ft_color_string(e, 4, 1), "reculer : ");
	mlx_string_put(e->mlx, e->win, 30, 165, ft_color_string(e, 5, 1), "droite : ");
	mlx_string_put(e->mlx, e->win, 30, 185, ft_color_string(e, 6, 1), "gauche : ");
	
	mlx_string_put(e->mlx, e->win, 150, 65, ft_color_string(e, 0, 2), ft_print_key(e->key->key_quit, e, &nb, 0));
	mlx_string_put(e->mlx, e->win, 150, 85, ft_color_string(e, 1, 2), ft_print_key(e->key->key_menu, e, &nb, 1));
	mlx_string_put(e->mlx, e->win, 150, 105, ft_color_string(e, 2, 2), ft_print_key(e->key->key_enter, e, &nb, 2));
	mlx_string_put(e->mlx, e->win, 150, 125, ft_color_string(e, 3, 2), ft_print_key(e->key->key_up, e, &nb, 3));
	mlx_string_put(e->mlx, e->win, 150, 145, ft_color_string(e, 4, 2), ft_print_key(e->key->key_down, e, &nb, 4));
	mlx_string_put(e->mlx, e->win, 150, 165, ft_color_string(e, 5, 2), ft_print_key(e->key->key_right, e, &nb, 5));
	mlx_string_put(e->mlx, e->win, 150, 185, ft_color_string(e, 6, 2), ft_print_key(e->key->key_left, e, &nb, 6));
}

void	ft_event_hud(t_key *key)
{
	if (key->time_menu == 0 && key->key_down_v == 1)
		key->pos_curseur++;
	if (key->time_menu == 0 && key->key_up_v == 1)
		key->pos_curseur--;
	if (key->pos_curseur > 6)
		key->pos_curseur = 0;
	if (key->pos_curseur < 0)
		key->pos_curseur = 6;
}

int		ft_check_key(t_env *e)
{
	int nb;

	if (e->key->new_key == e->key->key_quit && e->key->pos_curseur != 0)
		return (-1);
	if (e->key->new_key == e->key->key_menu && e->key->pos_curseur != 1)
		return (-1);
	if (e->key->new_key == e->key->key_enter && e->key->pos_curseur != 2)
		return (-1);
	if (e->key->new_key == e->key->key_up && e->key->pos_curseur != 3)
		return (-1);
	if (e->key->new_key == e->key->key_down && e->key->pos_curseur != 4)
		return (-1);
	if (e->key->new_key == e->key->key_left && e->key->pos_curseur != 5)
		return (-1);
	if (e->key->new_key == e->key->key_right && e->key->pos_curseur != 6)
		return (-1);
	nb = 1;
	ft_print_key(e->key->new_key, e, &nb , -1);
	return (nb);
}

void	ft_init_key_v(t_env *e)
{
		e->key->key_menu_v = 1;
		e->key->key_enter_v = 0;
		e->key->key_up_v = 0;
		e->key->key_down_v = 0;
		e->key->key_left_v = 0;
		e->key->key_right_v = 0;
}

void	ft_valide_key(t_env *e)
{
	if (e->key->pos_curseur == 0)
		e->key->key_quit = e->key->new_key;
	if (e->key->pos_curseur == 1)
		e->key->key_menu = e->key->new_key;
	if (e->key->pos_curseur == 2)
		e->key->key_enter = e->key->new_key;
	if (e->key->pos_curseur == 3)
		e->key->key_up = e->key->new_key;
	if (e->key->pos_curseur == 4)
		e->key->key_down = e->key->new_key;
	if (e->key->pos_curseur == 5)
		e->key->key_right = e->key->new_key;
	if (e->key->pos_curseur == 6)
		e->key->key_left = e->key->new_key;
	ft_init_key_v(e);
}

void	ft_menu(t_env *e)
{
	int ret;

	if (e->key->time_menu == 20)
		e->key->time_menu = 0;
	ft_event_hud(e->key);
	ft_cadre(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	if (e->key->add_new_key != 0)
	{
		ret = ft_check_key(e);
		if (ret < 0)
		{
			e->key->add_new_key = 1;
			if (ret == -1)
				mlx_string_put(e->mlx, e->win, 250, 65 + e->key->pos_curseur * 20, 0xff0000, "key already used !" );
		}
	}
	if (e->key->key_enter_v == 1 && e->key->add_new_key == 0 && e->key->key_enter_c == 1)
	{
		e->key->key_enter_v = 0;
		e->key->add_new_key = 1;

	}
	else if (e->key->key_enter_v == 1 && e->key->add_new_key == 2 && e->key->key_enter_c == 1)
	{
		ft_valide_key(e);
		e->key->add_new_key = 0;
		e->key->key_enter_v = 0;
	}
	ft_texte(e);
	if ((e->key->key_up_v == 1 || e->key->key_down_v) == 1 && e->key->add_new_key == 0)
		e->key->time_menu++;
}