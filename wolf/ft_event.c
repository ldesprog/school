/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldesprog <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/17 15:06:17 by ldesprog          #+#    #+#             */
/*   Updated: 2016/08/17 15:06:19 by ldesprog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_key_down_2(int keycode, t_env *e)
{
	if (e->key->add_new_key == 1)
	{
		e->key->add_new_key = 2;
		e->key->new_key = keycode;
	}
	if (keycode == e->key->key_enter)
	{
		e->key->key_enter_c++;
		e->key->key_enter_v = 1;
	}
	if (keycode == e->key->key_quit && e->key->key_menu_v == 1
		&& e->key->add_new_key == 0)
		e->key->key_menu_v = 0;
	else if (keycode == e->key->key_quit && e->key->add_new_key == 0)
		ft_free(e);
}

int		ft_key_down(int keycode, t_env *e)
{
	if (e->key->add_new_key == 0)
	{
		if (keycode == e->key->key_left)
			e->key->key_left_v = 1;
		else if (keycode == e->key->key_right)
			e->key->key_right_v = 1;
		else if (keycode == e->key->key_down)
			e->key->key_down_v = 1;
		else if (keycode == e->key->key_up)
			e->key->key_up_v = 1;
		else if (keycode == e->key->key_menu && e->key->key_menu_v == 0)
		{
			e->key->new_key = 0;
			e->key->time_menu = 0;
			e->key->pos_curseur = 0;
			e->key->key_menu_v = 1;
		}
		else if (keycode == e->key->key_menu && e->key->key_menu_v == 1)
			e->key->key_menu_v = 0;
		else if (keycode == e->key->key_action && e->key->key_menu_v == 0)
			ft_action(e);
	}
	ft_key_down_2(keycode, e);
	return (0);
}

int		ft_key_up(int keycode, t_env *e)
{
	if (keycode == e->key->key_left)
		e->key->key_left_v = 0;
	else if (keycode == e->key->key_right)
		e->key->key_right_v = 0;
	else if (keycode == e->key->key_down)
	{
		e->key->time_menu = 0;
		e->key->key_down_v = 0;
	}
	else if (keycode == e->key->key_up)
	{
		e->key->time_menu = 0;
		e->key->key_up_v = 0;
	}
	else if (keycode == e->key->key_enter)
	{
		e->key->key_enter_c = 0;
		e->key->key_enter_v = 0;
	}
	return (0);
}

int		ft_wolf(t_env *e)
{
	if (e->key->key_menu_v == 0)
	{
		if (e->key->key_left_v == 1)
			ft_tourne(TOURNE, e);
		if (e->key->key_right_v == 1)
			ft_tourne(-TOURNE, e);
		if (e->key->key_down_v == 1)
			ft_avance(-AVANCE, e);
		if (e->key->key_up_v == 1)
			ft_avance(AVANCE, e);
	}
	ft_raycast(e);
	return (0);
}

void	ft_free(t_env *env)
{
	int i;

	i = 0;
	while (i < env->map_hight / env->size)
		free(env->map[i++]);
	free(env->map);
	free(env->player->pos);
	free(env->player);
	mlx_destroy_window(env->mlx, env->win);
	free(env);
	exit(0);
}
