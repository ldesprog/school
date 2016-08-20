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

int		ft_key_down(int keycode, t_env *e)
{
	if (keycode == 53)
		ft_free(e);
	else if (keycode == 123)
		e->left = 1;
	else if (keycode == 124)
		e->right = 1;
	else if (keycode == 125)
		e->down = 1;
	else if (keycode == 126)
		e->up = 1;
	return (0);
}

int		ft_key_up(int keycode, t_env *e)
{
	if (keycode == 123)
		e->left = 0;
	else if (keycode == 124)
		e->right = 0;
	else if (keycode == 125)
		e->down = 0;
	else if (keycode == 126)
		e->up = 0;
	return (0);
}

int		ft_red_cross(t_env *e)
{
	ft_free(e);
	return (0);
}

int		ft_wolf(t_env *env)
{
	if (env->left == 1)
		ft_tourne(2, env);
	if (env->right == 1)
		ft_tourne(-2, env);
	if (env->down == 1)
		ft_avance(-2, env);
	if (env->up == 1)
		ft_avance(2, env);
	ft_raycast(env);
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
