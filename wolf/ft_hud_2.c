/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hud_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesprog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 17:37:36 by ldesprog          #+#    #+#             */
/*   Updated: 2016/10/19 17:37:38 by ldesprog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		ft_col_str(t_env *e, int ligne, int mode)
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

void	ft_texte_2(t_env *e)
{
	int nb;

	nb = 1;
	mlx_string_put(e->mlx, e->win, 150, 65, ft_col_str(e, 0, 2),
		ft_print_key(e->key->key_quit, e, &nb, 0));
	mlx_string_put(e->mlx, e->win, 150, 85, ft_col_str(e, 1, 2),
		ft_print_key(e->key->key_menu, e, &nb, 1));
	mlx_string_put(e->mlx, e->win, 150, 105, ft_col_str(e, 2, 2),
		ft_print_key(e->key->key_enter, e, &nb, 2));
	mlx_string_put(e->mlx, e->win, 150, 125, ft_col_str(e, 3, 2),
		ft_print_key(e->key->key_up, e, &nb, 3));
	mlx_string_put(e->mlx, e->win, 150, 145, ft_col_str(e, 4, 2),
		ft_print_key(e->key->key_down, e, &nb, 4));
	mlx_string_put(e->mlx, e->win, 150, 165, ft_col_str(e, 5, 2),
		ft_print_key(e->key->key_right, e, &nb, 5));
	mlx_string_put(e->mlx, e->win, 150, 185, ft_col_str(e, 6, 2),
		ft_print_key(e->key->key_left, e, &nb, 6));
	mlx_string_put(e->mlx, e->win, 150, 205, ft_col_str(e, 7, 2),
		ft_print_key(e->key->key_action, e, &nb, 7));
}

void	ft_texte(t_env *e)
{
	mlx_string_put(e->mlx, e->win, 150, 35, 0xffffff, "Menu d'option wolf3D");
	mlx_string_put(e->mlx, e->win, 30, 65, ft_col_str(e, 0, 1), "quitter : ");
	mlx_string_put(e->mlx, e->win, 30, 85, ft_col_str(e, 1, 1), "menu : ");
	mlx_string_put(e->mlx, e->win, 30, 105, ft_col_str(e, 2, 1), "valider : ");
	mlx_string_put(e->mlx, e->win, 30, 125, ft_col_str(e, 3, 1), "avancer : ");
	mlx_string_put(e->mlx, e->win, 30, 145, ft_col_str(e, 4, 1), "reculer : ");
	mlx_string_put(e->mlx, e->win, 30, 165, ft_col_str(e, 5, 1), "droite : ");
	mlx_string_put(e->mlx, e->win, 30, 185, ft_col_str(e, 6, 1), "gauche : ");
	mlx_string_put(e->mlx, e->win, 30, 205, ft_col_str(e, 7, 1), "action : ");
	ft_texte_2(e);
}

void	ft_event_hud(t_key *key)
{
	if (key->time_menu == 0 && key->key_down_v == 1)
		key->pos_curseur++;
	if (key->time_menu == 0 && key->key_up_v == 1)
		key->pos_curseur--;
	if (key->pos_curseur > 7)
		key->pos_curseur = 0;
	if (key->pos_curseur < 0)
		key->pos_curseur = 7;
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
	if (e->key->new_key == e->key->key_right && e->key->pos_curseur != 5)
		return (-1);
	if (e->key->new_key == e->key->key_left && e->key->pos_curseur != 6)
		return (-1);
	if (e->key->new_key == e->key->key_action && e->key->pos_curseur != 7)
		return (-1);
	nb = 1;
	ft_print_key(e->key->new_key, e, &nb, -1);
	return (nb);
}
