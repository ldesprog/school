/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hud.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesprog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 16:58:03 by ldesprog          #+#    #+#             */
/*   Updated: 2016/10/19 16:58:05 by ldesprog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	ft_cadre(t_env *e)
{
	int x;
	int y;

	x = 19;
	while (++x <= 530)
	{
		y = 19;
		while (++y <= 240)
		{
			if (y <= 25)
			{
				*(e->data + y * e->s_line / 4 + x) = 0x888888;
				*(e->data + (y + 215) * e->s_line / 4 + x) = 0x888888;
			}
			else if (x <= 25)
			{
				*(e->data + y * e->s_line / 4 + x) = 0x888888;
				*(e->data + y * e->s_line / 4 + (x + 505)) = 0x888888;
			}
			else if (x < 525 && y < 235)
				*(e->data + y * e->s_line / 4 + x) = 0x000000;
		}
	}
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
	if (e->key->pos_curseur == 7)
		e->key->key_action = e->key->new_key;
	ft_init_key_v(e);
}

void	ft_menu_2(t_env *e)
{
	if (e->key->key_enter_v == 1 && e->key->add_new_key == 0
		&& e->key->key_enter_c == 1)
	{
		e->key->key_enter_v = 0;
		e->key->add_new_key = 1;
		e->key->new_key = -1;
	}
	ft_texte(e);
	if ((e->key->key_up_v == 1 || e->key->key_down_v) == 1
		&& e->key->add_new_key == 0)
		e->key->time_menu++;
}

void	ft_menu(t_env *e)
{
	int ret;

	if (e->key->time_menu == 20)
		e->key->time_menu = 0;
	ft_event_hud(e->key);
	ft_cadre(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	if (e->key->add_new_key != 0 && e->key->new_key != -1)
	{
		ret = ft_check_key(e);
		if (ret < 0)
		{
			e->key->add_new_key = 1;
			if (ret == -1)
				mlx_string_put(e->mlx, e->win, 250, 65 + e->key->pos_curseur
					* 20, 0xff0000, "key already used !");
		}
		else
		{
			ft_valide_key(e);
			e->key->add_new_key = 0;
			e->key->key_enter_v = 0;
		}
	}
	ft_menu_2(e);
}
